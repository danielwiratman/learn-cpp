#include "logger.h"
#include <openssl/evp.h>
#include <openssl/ec.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>

void
run_generate_key(string type)
{
	Logger &l = Logger::get();

	EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_from_name(NULL, "EC", NULL);
	if (!ctx)
	{
		l.ERROR("failed to create context");
		return;
	}

	EVP_PKEY *key;

	if (type == "rsa")
	{
		key = EVP_RSA_gen(3072);
	}
	else if (type == "ec")
	{
		// openssl ecparam -list_curves
		string curve;

		curve = "brainpoolP512t1"; // kinda long 512 bits
		// curve = "secp112r1"; // short 112 bits

		key = EVP_EC_gen(curve.c_str());
	}
	else
	{
		l.FATAL("invalid type");
	}

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
