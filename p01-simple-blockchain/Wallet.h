#pragma once

#include <iostream>
#include <string>

using namespace std;

#define DEFAULT_BALANCE 5

class Wallet
{
	string name;
	double balance;

  public:
	Wallet(string name) : name(name), balance(DEFAULT_BALANCE)
	{
		cout << "Wallet " << name << " created" << endl;
	}
	~Wallet() { cout << "Wallet " << name << " destroyed" << endl; }

	string get_name();
	double get_balance();

	void set_balance(double balance);

	void print_info();
};
