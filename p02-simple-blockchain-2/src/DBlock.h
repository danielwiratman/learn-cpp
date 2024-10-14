#pragma once

#include "DTransaction.h"
#include <cstddef>
#include <cstdint>
#include <cstring>

using namespace std;

struct DBlock
{
	uint64_t blockNumber;
	array<byte, 32> prevBlockHash;
	uint32_t nonce;
	vector<DTransaction> transactions;

	DBlock(uint64_t blockNumber, array<byte, 32> prevBlockHash)
											: blockNumber(blockNumber),
											  prevBlockHash(prevBlockHash)
	{
	}
};
