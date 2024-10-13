#include "logger.h"

#include <ctime>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <random>
#include <sys/stat.h>
#include <thread>
#include <unistd.h>
#include <cstdio>

#define DATA_SIZE 1024 * 1024

Logger &l = Logger::get();

void
my_hash(unsigned char *data, int data_len, unsigned char *hash)
{
	EVP_MD_CTX *ctx = EVP_MD_CTX_create();
	if (ctx == NULL)
		l.FATAL("EVP_MD_CTX_create");
	if (EVP_DigestInit(ctx, EVP_sha256()) != 1)
		l.FATAL("EVP_DigestInit");
	if (EVP_DigestUpdate(ctx, data, data_len) != 1)
		l.FATAL("EVP_DigestUpdate");
	if (EVP_DigestFinal(ctx, hash, NULL) != 1)
		l.FATAL("EVP_DigestFinal");
	EVP_MD_CTX_destroy(ctx);
}

void
randomize_content(unsigned char *data, int data_size)
{
	// Create a random device and seed the generator
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 255);

	for (int i = 0; i < data_size; i++)
	{
		data[i] = dis(gen);
	}
}

void
write_file(const string &filename, unsigned char *buffer, int size)
{
	FILE *file = fopen(filename.c_str(), "wb");
	if (file)
	{
		fwrite(buffer, 1, size, file);
		fclose(file);
	}
	else
	{
		l.ERROR("Failed to open file: " + filename);
	}
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

void *
worker_function(void *arg)
{
	int thread_id = *(int *) arg;
	unsigned char *data = new unsigned char[DATA_SIZE];

	clock_t start_time, end_time;
	start_time = clock();

	int found = 0;

	while (1)
	{
		randomize_content(data, DATA_SIZE);
		unsigned char hash_buffer[SHA256_DIGEST_LENGTH];
		my_hash(data, DATA_SIZE, hash_buffer);

		bool first_8_bits_are_zero = hash_buffer[0] == 0;
		// bool first_16_bits_are_zero =
		// 	hash_buffer[0] == 0 && hash_buffer[1] == 0;

		if (first_8_bits_are_zero)
		{
			found++;
			write_file("file" + to_string(thread_id * 1000000 + found),
					   data,
					   DATA_SIZE);
			end_time = clock();
			l.INFO("Found file" + to_string(thread_id * 1000000 + found) +
				   "... took " +
				   to_string((double) (end_time - start_time) / CLOCKS_PER_SEC *
							 1000) +
				   " ms");
			start_time = clock();
		}
	}
	delete[] data;
	return nullptr;
}

int
main()
{
	print_story();

	const int num_threads = thread::hardware_concurrency();
	// const int num_threads = 1;

	l.INFO("Using " + to_string(num_threads) + " threads");

	vector<thread> threads;
	for (int i = 0; i < num_threads; ++i)
	{
		int thread_id = i;
		threads.emplace_back(worker_function, &thread_id);
	}
	for (auto &thread : threads)
	{
		thread.join();
	}

	return 0;
}
