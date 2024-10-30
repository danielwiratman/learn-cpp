#include <logger.h>
#include "dwlc.h"

auto &l = Logger::get();

int
main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 5, 6, 7, 1, 24, 12, 43, 1232 };
	auto *root = newBinaryTree(nums);
	root->print_info();
}
