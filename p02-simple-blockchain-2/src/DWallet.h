#pragma once

#include "utils.h"
#include <string>
#include <vector>

using namespace std;

class DWallet
{
	vector<unsigned char> privKey;
	vector<unsigned char> pubKey;

  public:
	string name;
	string address;

	DWallet(string name) : name(name)
	{
		KeyPair pair = genKeyPair();
		privKey = pair.privKey;
		pubKey = pair.pubKey;
		address = address_from_pubkey(pubKey.data(), pubKey.size());
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
