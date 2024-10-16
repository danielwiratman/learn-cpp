#pragma once

#include "DCTransaction.h"

class DCBlock
{
  public:
	long blockNumber;

	array<unsigned char, 32> prevBlockHash;

	DCBlock(long blockNumber, array<unsigned char, 32> prevBlockHash)
											: blockNumber(blockNumber),
											  prevBlockHash(prevBlockHash)
	{
	}

	uint32_t nonce;

	vector<DCTransaction> transactions;

	array<unsigned char, 32> hash;

	vector<unsigned char>
	serialize()
	{
		vector<unsigned char> result;

		vector<unsigned char> blockNumberBytes = my_to_bytes(blockNumber);

		vector<unsigned char> nonceBytes = my_to_bytes(nonce);

		result.insert(result.end(),
					  blockNumberBytes.begin(),
					  blockNumberBytes.end());

		result.insert(result.end(), prevBlockHash.begin(), prevBlockHash.end());

		result.insert(result.end(), nonceBytes.begin(), nonceBytes.end());

		vector<unsigned char> transactionBytes;
		for (auto tx : transactions)
		{
			transactionBytes.insert(transactionBytes.end(),
									tx.serialize().begin(),
									tx.serialize().end());
		}

		result.insert(result.end(),
					  transactionBytes.begin(),
					  transactionBytes.end());

		return result;
	}
};
