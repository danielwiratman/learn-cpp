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
	kthSmallest(TreeNode *root, int k)
	{
		int visitCount = 0;
		int result = INT_MIN;
		dfs(root, k, visitCount, result);
		return result;
	}

  private:
	void
	dfs(TreeNode *root, int k, int &visitCount, int &result)
	{
		if (!root)
			return;

		if (result != INT_MIN)
			return;

		dfs(root->left, k, visitCount, result);
		visit(root, k, visitCount, result);
		dfs(root->right, k, visitCount, result);
	}

	void
	visit(TreeNode *root, int k, int &visitCount, int &result)
	{
		visitCount++;
		if (visitCount == k)
			result = root->val;
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 5, 3, 6, 2, 4, INT_MIN, INT_MIN, 1 });
	int k = 3;
	l.INFO(Solution().kthSmallest(root, k));
}
