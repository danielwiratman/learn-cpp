#pragma once

#include "DCChain.h"
#include "utils.h"

class DCNode
{
	DCChain &chain;
	vector<DCTransaction> mempool;

	bool
	verify_tx(const DCTransaction tx)
	{
		(void) tx;
		return true;
	}

  public:
	DCNode(DCChain &chain) : chain(chain) {}

	void
	add_transaction(const DCTransaction tx)
	{
		mempool.push_back(tx);
	}

	void
	mine_new_block()
	{
		long newBlockNumber = chain.get_latest_block_number() + 1;
		array<unsigned char, 32> prevBlockHash = chain.get_latest_block_hash();

		DCBlock newBlock = DCBlock(newBlockNumber, prevBlockHash);

		for (auto tx : mempool)
		{
			if (!verify_tx(tx))
			{
				continue;
			}

			vector<unsigned char> txSerialized = tx.serialize();

			newBlock.transactionData.insert(newBlock.transactionData.end(),
											txSerialized.begin(),
											txSerialized.end());
		}

		newBlock.nonce = -1;

		do
		{
			newBlock.nonce++;
			vector<unsigned char> newBlockBytes = newBlock.serialize();
			newBlock.hash = my_sha256_hash(newBlockBytes);
		} while (!first_8_bits_are_zero(newBlock.hash));

		chain.add_block(newBlock);
	};
};
