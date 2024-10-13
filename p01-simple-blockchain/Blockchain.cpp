#include "Blockchain.h"

void
Blockchain::add_transaction(Transaction tx)
{
	tx.from->set_balance(tx.from->get_balance() - tx.amount);
	tx.to->set_balance(tx.to->get_balance() + tx.amount);

	this->transactions.push_back(tx);
}
