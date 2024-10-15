#pragma once

#include "DCBlock.h"
#include "DCMempool.h"

class DCChain
{
	vector<DCBlock> blocks;
	vector<DCMemPool *> registeredMemPools;

  public:
	DCChain(DCBlock genesisBlock) { blocks.push_back(genesisBlock); };

	void
	add_block(DCBlock block)
	{
		blocks.push_back(block);
	};

	void
	register_mempool(DCMemPool *memPool)
	{
		registeredMemPools.push_back(memPool);
	}

	void
	mine_new_block(string minerAddress)
	{
		for (auto memPool : registeredMemPools)
		{
			array<unsigned char, 32> emptyHash;
			DCTransaction tx(emptyHash, minerAddress, 0.1);
			memPool->add_transaction(tx, minerAddress);
		}
	}
};
