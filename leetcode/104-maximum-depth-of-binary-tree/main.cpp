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
	maxDepth(TreeNode *root)
	{
		if (!root || root->val == INT_MIN)
			return 0;
		int maxFromLeft = maxDepth(root->left);
		int maxFromRight = maxDepth(root->right);
		return max(maxFromLeft, maxFromRight) + 1;
	}
};

class SolutionQueue
{
  public:
	int
	maxDepth(TreeNode *root)
	{
		if (root == nullptr)
			return 0;

		int result = 0;

		queue<pair<TreeNode *, int>> q;
		q.push({ root, 1 });

		while (!q.empty())
		{
			pair<TreeNode *, int> curr = q.front();
			q.pop();
			result = max(result, curr.second);

			if (curr.first->left && curr.first->left->val != INT_MIN)
				q.push({ curr.first->left, curr.second + 1 });
			if (curr.first->right && curr.first->right->val != INT_MIN)
				q.push({ curr.first->right, curr.second + 1 });
		}

		return result;
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 3, 9, 20, INT_MIN, INT_MIN, 15, 7 });
	l.INFO(Solution().maxDepth(root));
}
