#pragma once

#include "Transaction.h"
#include <iostream>
#include <vector>

using namespace std;

class Blockchain
{
	vector<Transaction> transactions;

  public:
	void add_transaction(Transaction tx);

	inline void
	print_transactions()
	{
		cout << "[BLOCKCHAIN]" << endl;
		for (Transaction tx : transactions)
		{
			cout << "[TX] " << tx.from->get_name() << " -> "
				 << tx.to->get_name() << " : " << tx.amount << endl;
		}
	};
};
