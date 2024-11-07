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
	int
	goodNodes(TreeNode *root)
	{
		if (!root)
			return 0;

		int result = 0;
		dfs(root, &result, root->val);
		return result;
	}

  private:
	void
	dfs(TreeNode *root, int *result, int currSubtreeMax)
	{
		if (!root || root->val == INT_MIN)
			return;

		if (root->val >= currSubtreeMax)
		{
			currSubtreeMax = root->val;
			*result += 1;
		}

		dfs(root->left, result, currSubtreeMax);
		dfs(root->right, result, currSubtreeMax);
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 3, 1, 4, 3, INT_MIN, 1, 5 });
	l.INFO(Solution().goodNodes(root));
}
