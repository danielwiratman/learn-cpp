#pragma once

#include "utils.h"
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>

using namespace std;

struct DTransaction
{
	array<byte, 32> previousTransactionHash;
	string recipientAddress;
	uint64_t amount;

	array<byte, 32> signature;

	array<byte, 32> hash;

	DTransaction(array<byte, 32> previousTransactionHash,
				 string recipientAddress, uint64_t amount)
											: previousTransactionHash(
												  previousTransactionHash),
											  recipientAddress(
												  recipientAddress),
											  amount(amount){};
};
