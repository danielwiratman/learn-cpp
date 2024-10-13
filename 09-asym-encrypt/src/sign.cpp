#include "logger.h"
#include "utils.h"
#include <cstddef>
#include <openssl/crypto.h>
#include <openssl/cryptoerr_legacy.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <vector>

void
run_sign()
{
	Logger &l = Logger::get();

	FILE *privKeyFile = fopen("key", "r");
	if (!privKeyFile)
		l.FATAL("cannot open key files");

	EVP_PKEY *privKey = PEM_read_PrivateKey(privKeyFile, NULL, NULL, NULL);
	if (!privKey)
		l.FATAL("cannot read private key");

	l.INFO(EVP_PKEY_base_id(privKey) == EVP_PKEY_EC	 ? "EC" :
		   EVP_PKEY_base_id(privKey) == EVP_PKEY_RSA ? "RSA" :
													   "unknown");

	l.INFO(EVP_PKEY_bits(privKey));

	EVP_MD_CTX *ctx = EVP_MD_CTX_new();
	if (!ctx)
		l.FATAL("cannot create context");

	if (EVP_DigestSignInit(ctx, NULL, EVP_sha256(), NULL, privKey) <= 0)
		l.FATAL("cannot initialize digest");

	vector<byte> data = read_file("data.csv");

	if (EVP_DigestSignUpdate(ctx, data.data(), data.size()) <= 0)
		l.FATAL("cannot update digest");

	size_t signature_len = 0;
	if (EVP_DigestSignFinal(ctx, NULL, &signature_len) <= 0)
		l.FATAL("cannot sign");

	byte signature[signature_len];
	if (EVP_DigestSignFinal(ctx, (unsigned char *) signature, &signature_len) <=
		0)
	{
		ERR_print_errors_fp(stderr);
		l.FATAL("cannot sign");
	}

	l.INFO("signature created with len: " + to_string(signature_len));

	FILE *signatureFile = fopen("signature", "w");
	if (!signatureFile)
		l.FATAL("cannot open signature file");
	fwrite(signature, 1, signature_len, signatureFile);
	fclose(signatureFile);

	EVP_MD_CTX_free(ctx);
	EVP_PKEY_free(privKey);
}
