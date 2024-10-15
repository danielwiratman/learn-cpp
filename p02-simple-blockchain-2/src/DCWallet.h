#pragma once

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
