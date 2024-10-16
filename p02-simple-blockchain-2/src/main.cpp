#include "DCBlock.h"
#include "DCChain.h"
#include "DCNode.h"
#include "DCTransaction.h"
#include "DCWallet.h"
#include "logger.h"
#include "utils.h"

#include <cstdio>

Logger &l = Logger::get();

int
main()
{
	print_story();

	DCBlock genesisBlock(0, {});
	genesisBlock.hash = {};

	DCChain chain(genesisBlock);

	DCNode node(chain);

	DCWallet alice_wallet("alice");
	DCWallet bob_wallet("bob");
	DCWallet charlie_wallet("charlie");

	alice_wallet.print_info();
	bob_wallet.print_info();
	charlie_wallet.print_info();

	DCTransaction tx1({ TXInput({}, 0) }, { TXOutput(bob_wallet.address, 5) });
	DCTransaction tx2({ TXInput({}, 0) }, { TXOutput(bob_wallet.address, 5) });
	DCTransaction tx3({ TXInput({}, 0) }, { TXOutput(bob_wallet.address, 5) });

	node.add_transaction(tx1);
	node.add_transaction(tx2);
	node.add_transaction(tx3);

	node.mine_new_block();

	chain.print_info();
}
