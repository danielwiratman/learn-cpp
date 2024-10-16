#pragma once

#include "DCBlock.h"
#include "DCTransaction.h"

#include <algorithm>
#include <unordered_map>

// Note: in this implementation, the map key for utxoMap is a string, while the
// data inside is actually 32 byte transaction hash. This is because the key is
// used as a map key, and an array cannot be used as a map key.
class DCUTXOSet
{
  public:
	// map of transaction hash as string to vector of UTXOs
	unordered_map<string, vector<TXOutput>> utxoMap;

	// This function traverses through all unspent transaction outputs,
	// and returns the UTXOs that belong to the given wallet address
	unordered_map<string, vector<TXOutput>>
	get_utxo_for_wallet(const string &walletAddress)
	{
		// map of transaction hash as string to vector of UTXOs
		unordered_map<string, vector<TXOutput>> utxoForWallet;

		for (const auto &[txAddress, txOutputs] : utxoMap)
		{
			for (const auto &txOutput : txOutputs)
			{
				if (txOutput.recipientAddress == walletAddress)
				{
					utxoForWallet[txAddress].push_back(txOutput);
				}
			}
		}

		return utxoForWallet;
	}

	void
	update_utxo_set_with_new_block(const DCBlock &block)
	{
		for (auto tx : block.transactions)
		{
			// remove spent UTXOs
			for (const auto &txInput : tx.get_inputs())
			{
				auto &outputs =
					utxoMap[to_string_multi(txInput.previousTxHash)];

				if (txInput.outputIndex < outputs.size())
					outputs.erase(outputs.begin() + txInput.outputIndex);
			}

			utxoMap[to_string_multi(tx.get_hash())] = tx.get_outputs();
		}
	}
};
