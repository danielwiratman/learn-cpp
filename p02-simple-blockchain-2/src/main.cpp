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
	DCTransaction tx1(emptyHash, bob_wallet.address, 0.5);
	memPool.add_transaction(tx1, alice_wallet.address);

	// Charlie -> Bob 1.5 dccoins
	DCTransaction tx2(emptyHash, bob_wallet.address, 1.5);
	memPool.add_transaction(tx2, charlie_wallet.address);

	// Bob -> Alice 0.1 dccoins
	DCTransaction tx3(emptyHash, alice_wallet.address, 0.1);
	memPool.add_transaction(tx3, bob_wallet.address);
}
