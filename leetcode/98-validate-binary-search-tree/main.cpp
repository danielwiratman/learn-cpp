#include <climits>
#include <vector>
#include <string>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	bool
	isValidBST(TreeNode *root)
	{
		if (!root)
			return true;

		if (root->left)
		{
			if (!(root->val > root->left->val))
				return false;
		}

		if (root->right)
		{
			if (!(root->val < root->right->val))
				return false;
		}

		return isValidBST(root->left) && isValidBST(root->right);
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 5, 4, 6, INT_MIN, INT_MIN, 3, 7 });
	root->print_info();
}
