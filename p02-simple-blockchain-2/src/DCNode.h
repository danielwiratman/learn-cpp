#pragma once

#include "DCChain.h"
#include "DCUTXOSet.h"
#include "DCWallet.h"
#include "utils.h"

class DCNode
{
	DCChain &chain;
	DCUTXOSet utxoSet;

	vector<DCTransaction> mempool;

	bool
	verify_tx(const DCTransaction tx)
	{
		(void) tx;
		return true;
	}

  public:
	DCNode(DCChain &chain, DCUTXOSet &utxoSet)
											: chain(chain), utxoSet(utxoSet){};

	void
	add_transaction(const DCTransaction &tx)
	{
		mempool.push_back(tx);
	}

	void
	mine_new_block(const DCWallet &minerWallet)
	{
		long newBlockNumber = chain.get_latest_block_number() + 1;

		array<unsigned char, 32> prevBlockHash = chain.get_latest_block_hash();

		DCBlock newBlock = DCBlock(newBlockNumber, prevBlockHash);

		// reward miner
		mempool.push_back(
			DCTransaction({}, { TXOutput(minerWallet.address, 10) }));

		for (auto tx : mempool)
		{
			if (!verify_tx(tx))
			{
				continue;
			}

			newBlock.transactions.push_back(tx);
		}

		newBlock.nonce = -1;

		do
		{
			newBlock.nonce++;
			vector<unsigned char> newBlockBytes = newBlock.serialize();
			newBlock.hash = my_sha256_hash(newBlockBytes);
		} while (!first_8_bits_are_zero(newBlock.hash));

		chain.add_block(newBlock);

		mempool.clear();
	};
};
