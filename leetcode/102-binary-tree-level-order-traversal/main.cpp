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
	vector<vector<int>>
	levelOrder(TreeNode *root)
	{
		if (!root)
			return {};

		vector<vector<int>> result{};
		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty())
		{
			int levelSize = q.size();
			vector<int> level(levelSize);

			for (int i = 0; i < levelSize; i++)
			{
				TreeNode *curr = q.front();
				q.pop();
				level[i] = curr->val;
				if (curr->left)
					q.push(curr->left);
				if (curr->right)
					q.push(curr->right);
			}

			result.push_back(level);
		}

		return result;
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 3, 9, 20, INT_MIN, INT_MIN, 15, 7 });
	l.INFO(Solution().levelOrder(root));
}
