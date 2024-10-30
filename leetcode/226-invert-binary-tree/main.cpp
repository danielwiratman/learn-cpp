#include <vector>
#include <string>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	TreeNode *
	invertTree(TreeNode *root)
	{
		if (root == nullptr)
			return nullptr;

		queue<TreeNode *> q;
		q.push(root);

		while (!q.empty())
		{
			TreeNode *curr = q.front();
			q.pop();
			swap(curr->left, curr->right);
			if (curr->left)
				q.push(curr->left);
			if (curr->right)
				q.push(curr->right);
		}

		return root;
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 4, 2, 7, 1, 3, 6, 9 });
	root = Solution().invertTree(root);
	root->print_info();
}
