#pragma once

#include "logger.h"

#include <cstdio>
#include <openssl/evp.h>
#include <openssl/ec.h>

extern Logger &l;

inline void
print_story()
{
	FILE *story_file = fopen("story.txt", "r");
	if (story_file == NULL)
		l.FATAL("could not open story file.");

	int ch = 0;
	do
	{
		ch = fgetc(story_file);
		if (ch != EOF)
			putchar(ch);
	} while (ch != EOF);

	fclose(story_file);
}

inline void
my_sha256_hash(unsigned char *input, size_t input_length, unsigned char *output)
{
	EVP_MD_CTX *ctx;

	ctx = EVP_MD_CTX_create();
	if (ctx == NULL)
		l.FATAL("EVP_MD_CTX_create");

	if (EVP_DigestInit(ctx, EVP_sha256()) != 1)
		l.FATAL("EVP_DigestInit");

	if (EVP_DigestUpdate(ctx, input, input_length) != 1)
		l.FATAL("EVP_DigestUpdate");

	if (EVP_DigestFinal(ctx, output, NULL) != 1)
		l.FATAL("EVP_DigestFinal");

	EVP_MD_CTX_destroy(ctx);
}

inline void
my_ripemd160_hash(unsigned char *input, size_t input_length,
				  unsigned char *output)
{
	EVP_MD_CTX *ctx;

	ctx = EVP_MD_CTX_create();
	if (ctx == NULL)
		l.FATAL("EVP_MD_CTX_create");

	if (EVP_DigestInit(ctx, EVP_ripemd160()) != 1)
		l.FATAL("EVP_DigestInit");

	if (EVP_DigestUpdate(ctx, input, input_length) != 1)
		l.FATAL("EVP_DigestUpdate");

	if (EVP_DigestFinal(ctx, output, NULL) != 1)
		l.FATAL("EVP_DigestFinal");

	EVP_MD_CTX_destroy(ctx);
}

inline string
encode_base58(const unsigned char *input, size_t input_length)
{
	const char *base58_chars =
		"123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

	vector<unsigned char> temp(input, input + input_length);
	string result;

	while (!temp.empty() && temp[0] == 0)
	{
		result += '1';
		temp.erase(temp.begin());
	}

	vector<unsigned char> encoded;
	while (!temp.empty())
	{
		int carry = 0;
		for (auto &byte : temp)
		{
			int value = (carry << 8) + byte;
			byte = value / 58;
			carry = value % 58;
		}
		encoded.push_back(carry);
		while (!temp.empty() && temp[0] == 0)
			temp.erase(temp.begin());
	}

	for (auto it = encoded.rbegin(); it != encoded.rend(); ++it)
		result += base58_chars[*it];

	return result;
}

inline string
address_from_pubkey(unsigned char *pubkey, int pubkey_length)
{
	unsigned char sha_hash[32];
	my_sha256_hash(pubkey, pubkey_length, sha_hash);

	unsigned char ripemd_hash[20];
	my_ripemd160_hash(sha_hash, 32, ripemd_hash);

	return encode_base58(ripemd_hash, 20);
}

struct KeyPair
{
	vector<unsigned char> pubKey;
	vector<unsigned char> privKey;
};

inline KeyPair
genKeyPair()
{
	EVP_PKEY_CTX *ctx = EVP_PKEY_CTX_new_from_name(NULL, "EC", NULL);
	if (!ctx)
	{
		l.FATAL("failed to create context");
	}

	EVP_PKEY *key = EVP_EC_gen("brainpoolP512t1");
	if (!key)
		l.FATAL("failed to generate key");

	int pubLen = i2d_PublicKey(key, NULL);
	vector<unsigned char> ucharPubKey(pubLen);
	unsigned char *pubKeyPtr = ucharPubKey.data();
	i2d_PublicKey(key, &pubKeyPtr);

	int privLen = i2d_PrivateKey(key, NULL);
	vector<unsigned char> ucharPrivKey(privLen);
	unsigned char *privKeyPtr = ucharPrivKey.data();
	i2d_PrivateKey(key, &privKeyPtr);

	KeyPair result;
	result.pubKey = ucharPubKey;
	result.privKey = ucharPrivKey;

	return result;
}
