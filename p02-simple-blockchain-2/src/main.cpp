#include "DCBlock.h"
#include "DCChain.h"
#include "DCNode.h"
#include "DCTransaction.h"
#include "DCUTXOSet.h"
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
	DCChain chain(genesisBlock);
	DCUTXOSet utxoSet;
	DCNode node(chain, utxoSet);

	DCWallet satoshi_wallet("satoshi");
	DCWallet alice_wallet("alice");
	DCWallet bob_wallet("bob");
	DCWallet charlie_wallet("charlie");

	// Coinbase transaction
	node.add_transaction(DCTransaction({}, {}));
	node.mine_new_block(satoshi_wallet);
	utxoSet.update_utxo_set_with_new_block(chain.get_latest_block());

	node.add_transaction(
		DCTransaction({ TXInput({}, 0) }, { TXOutput(bob_wallet.address, 5) }));
	node.add_transaction(
		DCTransaction({ TXInput({}, 0) }, { TXOutput(bob_wallet.address, 5) }));
	node.add_transaction(
		DCTransaction({ TXInput({}, 0) }, { TXOutput(bob_wallet.address, 5) }));

	chain.print_info();
}
