#include "logger.h"

#include <ctime>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <sys/stat.h>

#define forever for (;;)
#define DATA_SIZE 1024 * 1024

Logger &l = Logger::get();

void
my_hash(unsigned char *data, int data_len, unsigned char *hash)
{
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

void
randomize_content(unsigned char *data, int data_size)
{
	for (int i = 0; i < data_size; i++)
		data[i] = rand() % 256;
}

void
write_file(string filename, unsigned char *buffer, int size)
{
	FILE *file = fopen(filename.c_str(), "wb");
	fwrite(buffer, 1, size, file);
	fclose(file);
}

void
print_story()
{
	printf("The program does the following:\n"
		   " 1. Generate a random byte array of 1 MB long.\n"
		   " 2. Hash the string using SHA256.\n"
		   " 3. If the first n bits of the hash are all 0s, save the byte "
		   "array as fileXX\n"
		   " 4. Loop until file10.\n"
		   "\n");
}

int
main()
{
	print_story();

	unsigned char *data = new unsigned char[DATA_SIZE];

	int iterations = 0;
	int found = 0;

	clock_t start, end;

	start = clock();

	forever
	{
		randomize_content(data, DATA_SIZE);

		unsigned char hash_buffer[SHA256_DIGEST_LENGTH];
		my_hash(data, DATA_SIZE, hash_buffer);

		// bool first_30_bits_are_zero =
		// 	hash_buffer[0] == 0 && hash_buffer[1] == 0 && hash_buffer[2] == 0 &&
		// 	(hash_buffer[3] & 0xFC) == 0;

		// bool first_12_bits_are_zero =
		// 	hash_buffer[0] == 0 && (hash_buffer[1] & 0xF0) == 0;

		bool first_8_bits_are_zero = hash_buffer[0] == 0;

		if (first_8_bits_are_zero)
		{
			write_file("file" + to_string(found), data, DATA_SIZE);
			found++;
			end = clock();
			l.INFO("Found file" + to_string(found) + "... took " +
				   to_string((double) (end - start) / CLOCKS_PER_SEC * 1000) +
				   " ms");
			start = clock();
		}

		if (found == 10)
			break;

		if (iterations % 1000 == 0)
			l.INFO("Iterations: " + to_string(iterations));

		iterations++;
	}

	l.INFO("Found " + to_string(found) + " files in " + to_string(iterations) +
		   " iterations");

	delete[] data;
}
