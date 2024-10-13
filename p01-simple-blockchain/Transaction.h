#pragma once

#include "Wallet.h"

struct Transaction
{
	Wallet *from;
	Wallet *to;
	double amount;

	Transaction(Wallet *from, Wallet *to, double amount)
											: from(from), to(to), amount(amount)
	{
	}
};
