#pragma once

#include "DCTransaction.h"
#include <cstddef>
#include <cstdint>
#include <cstring>

class DCBlock
{
	uint64_t blockNumber;
	array<unsigned char, 32> prevBlockHash;
	uint32_t nonce;
	vector<DCTransaction> transactions;

  public:
	DCBlock(uint64_t blockNumber, array<unsigned char, 32> prevBlockHash)
											: blockNumber(blockNumber),
											  prevBlockHash(prevBlockHash)
	{
	}
};
