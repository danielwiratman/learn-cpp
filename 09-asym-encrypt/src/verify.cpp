#include "utils.h"
#include "logger.h"
#include <openssl/pem.h>

void
run_verify()
{
	Logger &l = Logger::get();

	vector<byte> signature_vec = read_file("signature");
	vector<byte> data = read_file("data.csv");

	FILE *pubKeyFile = fopen("key.pub", "r");
	if (!pubKeyFile)
		l.FATAL("cannot open key.pub files");

	EVP_PKEY *pubKey = PEM_read_PUBKEY(pubKeyFile, NULL, NULL, NULL);
	if (!pubKey)
		l.FATAL("cannot read public key");

	l.INFO(EVP_PKEY_base_id(pubKey) == EVP_PKEY_EC ? "EC" : "unknown");
	l.INFO(EVP_PKEY_bits(pubKey));

	EVP_MD_CTX *ctx = EVP_MD_CTX_new();
	if (!ctx)
		l.FATAL("cannot create context");

	if (EVP_DigestVerifyInit(ctx, NULL, EVP_sha256(), NULL, pubKey) <= 0)
		l.FATAL("cannot initialize digest");

	if (EVP_DigestVerifyUpdate(ctx, data.data(), data.size()) <= 0)
		l.FATAL("cannot update digest");

	if (EVP_DigestVerifyFinal(ctx,
							  (unsigned char *) signature_vec.data(),
							  signature_vec.size()) <= 0)
		l.FATAL("signature not verified");

	l.INFO("signature verified");

	EVP_MD_CTX_free(ctx);
	EVP_PKEY_free(pubKey);
}
