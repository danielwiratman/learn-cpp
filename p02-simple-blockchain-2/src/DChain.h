#pragma once

#include "DBlock.h"
class DChain
{
	DBlock *head;
	DBlock *tail;
	int blockCount;

  public:
	DChain(DBlock *genesisBlock) { head = tail = genesisBlock; };
	void add_block(DBlock *block);
};
