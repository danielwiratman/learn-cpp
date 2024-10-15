#pragma once

#include "DCTransaction.h"
#include <cstddef>
#include <cstdint>
#include <cstring>

struct DCBlock
{
	uint64_t blockNumber;
	array<unsigned char, 32> prevBlockHash;
	uint32_t nonce;
	vector<DCTransaction> transactions;

	DCBlock(uint64_t blockNumber, array<unsigned char, 32> prevBlockHash)
											: blockNumber(blockNumber),
											  prevBlockHash(prevBlockHash)
	{
	}
};
