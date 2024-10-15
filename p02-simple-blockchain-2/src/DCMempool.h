#pragma once

#include "DCTransaction.h"

class DCMemPool
{
	vector<pair<DCTransaction, string>> pool;

  public:
	void
	add_transaction(DCTransaction tx, string sender)
	{
		pool.push_back(make_pair(tx, sender));
	}
};
