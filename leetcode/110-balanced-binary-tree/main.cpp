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
	isBalanced(TreeNode *root)
	{
		return dfs(root).first;
	}

  private:
	pair<bool, int>
	dfs(TreeNode *root)
	{
		if (!root || root->val == INT_MIN)
			return { 1, 0 };

		auto left = dfs(root->left);
		auto right = dfs(root->right);

		bool isBalanced =
			left.first && right.first && abs(left.second - right.second) < 2;
		int height = max(left.second, right.second) + 1;

		return { isBalanced, height };
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 3, 9, 20, INT_MIN, INT_MIN, 15, 7 });
	l.INFO(Solution().isBalanced(root));
}
