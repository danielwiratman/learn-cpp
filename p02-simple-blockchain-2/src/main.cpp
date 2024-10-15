#include "DCBlock.h"
#include "DCChain.h"
#include "DCMempool.h"
#include "DCWallet.h"
#include "logger.h"
#include "utils.h"

#include <cstdio>

Logger &l = Logger::get();

int
main()
{
	print_story();

	array<unsigned char, 32> emptyHash;

	DCBlock genesisBlock(0, emptyHash);

	DCChain chain(genesisBlock);

	DCMemPool memPool;
	chain.register_mempool(&memPool);

	DCWallet alice_wallet("alice");
	DCWallet bob_wallet("bob");
	DCWallet charlie_wallet("charlie");

	alice_wallet.print_info();
	bob_wallet.print_info();
	charlie_wallet.print_info();

	// Alice -> Bob 0.5 dccoins

	// Charlie -> Bob 1.5 dccoins

	// Bob -> Alice 0.1 dccoins
}
