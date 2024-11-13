#include <climits>
#include <vector>
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
		return dfs(root, LONG_MIN, LONG_MAX);
	}

  private:
	bool
	dfs(TreeNode *root, long currMin, long currMax)
	{
		if (!root)
			return true;

		if (root->val <= currMin || root->val >= currMax)
			return false;

		return dfs(root->left, currMin, root->val) &&
			   dfs(root->right, root->val, currMax);
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 5, 1, 4, INT_MIN, INT_MIN, 3, 6 });
	l.INFO(Solution().isValidBST(root));
}
