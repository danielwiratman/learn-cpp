#include <vector>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	diameterOfBinaryTree(TreeNode *root)
	{
		int result = 0;
		dfs(root, result);
		return result;
	}

  private:
	int
	dfs(TreeNode *curr, int &res)
	{
		if (!curr)
			return 0;

		int left = dfs(curr->left, res);
		int right = dfs(curr->right, res);
		res = max(res, left + right);

		return max(left, right) + 1;
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 1, 2, 3, 4, 5 });
	l.INFO(Solution().diameterOfBinaryTree(root));
}
