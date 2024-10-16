#pragma once

#include "DCTransaction.h"
#include "DCUTXOSet.h"
#include "utils.h"
#include <string>
#include <vector>

class DCWallet
{
	vector<unsigned char> privKey;
	vector<unsigned char> pubKey;

  public:
	string name;
	string address;

	DCWallet(string name) : name(name)
	{
		KeyPair pair = genKeyPair();
		privKey = pair.privKey;
		pubKey = pair.pubKey;
		address = address_from_pubkey(pubKey);
	}

	vector<TXOutput>
	get_utxo(DCUTXOSet &utxoSet)
	{
		vector<TXOutput> utxos;

		for (const auto &[txHash, txOutputs] :
			 utxoSet.get_utxo_for_wallet(address))
		{
			for (const auto &txOutput : txOutputs)
			{
				if (txOutput.recipientAddress == address)
				{
					utxos.push_back(txOutput);
				}
			}
		}

		return utxos;
	}

	void
	print_info()
	{
		printf("[WALLET]\n"
			   "name: %s\n"
			   "address: %s\n"
			   "\n",
			   name.c_str(),
			   address.c_str());
	}
};
