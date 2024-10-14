#include "DBlock.h"
#include "DChain.h"
#include "DWallet.h"
#include "logger.h"
#include "utils.h"

#include <cstdio>

Logger &l = Logger::get();

int
main()
{
	print_story();

	array<byte, 32> emptyHash;

	DBlock genesisBlock(0, emptyHash);

	DChain chain(&genesisBlock);

	DWallet alice_wallet("alice");
	DWallet bob_wallet("bob");
	DWallet charlie_wallet("charlie");

	alice_wallet.print_info();
	bob_wallet.print_info();
	charlie_wallet.print_info();
}
