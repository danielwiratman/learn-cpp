#include "Wallet.h"
#include <string>

using namespace std;

string
Wallet::get_name()
{
	return this->name;
}

double
Wallet::get_balance()
{
	return this->balance;
}

void
Wallet::set_balance(double balance)
{
	this->balance = balance;
}

void
Wallet::print_info()
{
	cout << "[WALLET] " << this->name << " : " << this->balance << endl;
}
