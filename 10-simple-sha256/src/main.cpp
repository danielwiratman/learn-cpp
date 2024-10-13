#include "logger.h"

#include <openssl/sha.h>
#include <openssl/evp.h>
#include <sys/stat.h>

Logger &l = Logger::get();

void
my_hash(unsigned char *data, int data_len, unsigned char *hash)
{
	l.INFO("starting hash");

	// EVP -> OpenSSL Envelope, a high level cryptographic API, that
	// combines stuff MD -> Message Digest, basically result of a hash
	// function
	EVP_MD_CTX *ctx;

	ctx = EVP_MD_CTX_create();
	if (ctx == NULL)
		l.FATAL("EVP_MD_CTX_create");

	if (EVP_DigestInit(ctx, EVP_sha256()) != 1)
		l.FATAL("EVP_DigestInit");

	if (EVP_DigestUpdate(ctx, data, data_len) != 1)
		l.FATAL("EVP_DigestUpdate");

	if (EVP_DigestFinal(ctx, hash, NULL) != 1)
		l.FATAL("EVP_DigestFinal");

	EVP_MD_CTX_destroy(ctx);
};

long
get_file_size(const char *filename)
{
	struct stat st;
	if (stat(filename, &st) != 0)
		return -1;
	return st.st_size;
}

void
read_file(const char *filename, unsigned char *buffer)
{
	struct stat st;
	if (stat(filename, &st) != 0)
		return;

	FILE *file = fopen(filename, "rb");
	fread(buffer, 1, st.st_size, file);
	fclose(file);
}

void
write_file(const char *filename, unsigned char *buffer, int size)
{
	FILE *file = fopen(filename, "wb");
	fwrite(buffer, 1, size, file);
	fclose(file);
}

int
main(int args, char **argv)
{
	if (args < 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
	}

	long data_size = get_file_size(argv[1]);
	if (data_size < 0)
		l.FATAL("get_file_size");

	unsigned char *data = new unsigned char[data_size];
	read_file(argv[1], data);

	unsigned char hash_buffer[SHA256_DIGEST_LENGTH];
	my_hash(data, data_size, hash_buffer);

	write_file("hash", hash_buffer, SHA256_DIGEST_LENGTH);

	l.INFO("hash done");

	delete[] data;
}
