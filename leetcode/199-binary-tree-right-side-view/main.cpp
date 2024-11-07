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
	vector<int>
	rightSideView(TreeNode *root)
	{
		if (!root)
			return {};

		vector<int> result;

		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty())
		{
			vector<int> level;
			int levelSize = q.size();
			for (int i = 0; i < levelSize; i++)
			{
				TreeNode *curr = q.front();
				q.pop();
				level.push_back(curr->val);

				if (curr->left)
					q.push(curr->left);

				if (curr->right)
					q.push(curr->right);
			}
			result.push_back(level[level.size() - 1]);
		}

		return result;
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 1, 2, 3, INT_MIN, 5, INT_MIN, 4 });
	l.INFO(Solution().rightSideView(root));
}
