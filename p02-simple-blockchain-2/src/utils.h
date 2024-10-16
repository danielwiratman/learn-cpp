#pragma once

#include "logger.h"

#include <array>
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

inline array<unsigned char, 32>
my_sha256_hash(const vector<unsigned char> &input)
{
	EVP_MD_CTX *ctx = EVP_MD_CTX_create();
	if (ctx == NULL)
		l.FATAL("EVP_MD_CTX_create");

	if (EVP_DigestInit(ctx, EVP_sha256()) != 1)
		l.FATAL("EVP_DigestInit");

	if (EVP_DigestUpdate(ctx, input.data(), input.size()) != 1)
		l.FATAL("EVP_DigestUpdate");

	array<unsigned char, 32> result;
	if (EVP_DigestFinal(ctx, result.data(), NULL) != 1)
		l.FATAL("EVP_DigestFinal");

	EVP_MD_CTX_destroy(ctx);

	return result;
}

inline array<unsigned char, 20>
my_ripemd160_hash(const vector<unsigned char> &input)
{
	EVP_MD_CTX *ctx = EVP_MD_CTX_create();
	if (ctx == NULL)
		l.FATAL("EVP_MD_CTX_create");

	if (EVP_DigestInit(ctx, EVP_ripemd160()) != 1)
		l.FATAL("EVP_DigestInit");

	if (EVP_DigestUpdate(ctx, input.data(), input.size()) != 1)
		l.FATAL("EVP_DigestUpdate");

	array<unsigned char, 20> result;
	if (EVP_DigestFinal(ctx, result.data(), NULL) != 1)
		l.FATAL("EVP_DigestFinal");

	EVP_MD_CTX_destroy(ctx);

	return result;
}

inline string
encode_base58(const vector<unsigned char> &input)
{
	const char *base58_chars =
		"123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

	vector<unsigned char> temp(input.begin(), input.end());
	string result;
	for (auto it = temp.begin(); it != temp.end() && *it == 0; ++it)
	{
		result += '1';
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
		{
			temp.erase(temp.begin());
		}
	}

	for (auto it = encoded.rbegin(); it != encoded.rend(); ++it)
	{
		result += base58_chars[*it];
	}

	return result;
}

inline string
address_from_pubkey(const vector<unsigned char> &pubKey)
{
	array<unsigned char, 32> sha_hash = my_sha256_hash(pubKey);
	vector<unsigned char> sha_hash_vec(sha_hash.begin(), sha_hash.end());
	array<unsigned char, 20> ripemd_hash = my_ripemd160_hash(sha_hash_vec);
	vector<unsigned char> ripemd_hash_vec(ripemd_hash.begin(),
										  ripemd_hash.end());
	return encode_base58(ripemd_hash_vec);
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

template<typename T>
inline vector<unsigned char>
my_to_bytes(T input)
{
	vector<unsigned char> result(sizeof(T));
	memcpy(result.data(), &input, sizeof(T));
	return result;
}

template<typename T>
inline bool
first_8_bits_are_zero(T &bytes)
{
	return bytes[0] == 0;
}

inline void
empty_line()
{
	printf("\n");
}

template<typename T>
inline string
to_hex(const T &bytes)
{
	const char hex_chars[] = "0123456789abcdef";
	string result;
	result.reserve(bytes.size() * 2);

	for (auto &b : bytes)
	{
		result.push_back(hex_chars[(b >> 4) & 0x0F]);
		result.push_back(hex_chars[b & 0x0F]);
	}
	return result;
}
