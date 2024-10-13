#include "logger.h"
#include <openssl/evp.h>
#include <openssl/ec.h>
#include <openssl/pem.h>

void
run_generate_key()
{
	Logger &l = Logger::get();

	EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_from_name(NULL, "EC", NULL);
	if (!ctx)
	{
		l.ERROR("failed to create context");
		return;
	}

	EVP_PKEY *key = EVP_EC_gen("P-256");
	if (!key)
	{
		l.ERROR("failed to generate key");
		return;
	}

	FILE *pubKeyFile = fopen("key.pub", "w");
	if (!pubKeyFile)
	{
		l.ERROR("failed to open key.pub");
		return;
	}

	PEM_write_PUBKEY(pubKeyFile, key);
	fclose(pubKeyFile);

	FILE *privKeyFile = fopen("key", "w");
	if (!privKeyFile)
	{
		l.ERROR("failed to open key");
		return;
	}

	PEM_write_PrivateKey(privKeyFile, key, NULL, NULL, 0, NULL, NULL);
	fclose(privKeyFile);

	EVP_PKEY_free(key);

	l.INFO("key generated");
}
