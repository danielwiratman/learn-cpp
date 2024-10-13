#include "Blockchain.h"
#include "misc.h"
#include <memory>

using namespace std;

int
main()
{
	print_story();

	auto alice_wallet = make_unique<Wallet>("Alice");
	auto bob_wallet = make_unique<Wallet>("Bob");
	auto charlie_wallet = make_unique<Wallet>("Charlie");
	empty_line();

	alice_wallet->print_info();
	bob_wallet->print_info();
	charlie_wallet->print_info();
	empty_line();

	Blockchain blockchain = Blockchain();

	blockchain.add_transaction(
		Transaction(alice_wallet.get(), bob_wallet.get(), 0.5));
	blockchain.add_transaction(
		Transaction(charlie_wallet.get(), bob_wallet.get(), 1.5));
	blockchain.add_transaction(
		Transaction(bob_wallet.get(), alice_wallet.get(), 0.1));
	blockchain.print_transactions();
	empty_line();

	alice_wallet->print_info();
	bob_wallet->print_info();
	charlie_wallet->print_info();
	empty_line();
}
