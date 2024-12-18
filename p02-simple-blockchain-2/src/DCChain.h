#pragma once

#include "DCBlock.h"

class DCChain
{
	vector<DCBlock> blocks;

  public:
	DCChain(const DCBlock genesisBlock) { blocks.push_back(genesisBlock); };

	void
	add_block(DCBlock block)
	{
		blocks.push_back(block);
	};

	long
	get_latest_block_number()
	{
		return blocks.back().blockNumber;
	}

	array<unsigned char, 32>
	get_latest_block_hash()
	{
		return blocks.back().hash;
	}

	DCBlock
	get_latest_block()
	{
		return blocks.back();
	}

	void
	print_info()
	{
		printf("[CHAIN]\n"
			   "size: %ld\n"
			   "latest block number: %ld\n"
			   "latest block hash: ",
			   blocks.size(),
			   get_latest_block_number());
		printf("%s\n", to_hex_multi(get_latest_block_hash()).c_str());
		empty_line();
	}
};
