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
	TreeNode *
	lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if ((p->val == root->val) || (q->val == root->val) ||
			(p->val > root->val && q->val < root->val) ||
			(p->val < root->val && q->val > root->val)

		)
			return root;

		if (p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);

		if (p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);

		return nullptr;
	}
};

int
main()
{
	TreeNode *root =
		newBinaryTree({ 6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5 });
	TreeNode *p = newBinaryTree({ 2 });
	TreeNode *q = newBinaryTree({ 8 });

	TreeNode *result = Solution().lowestCommonAncestor(root, p, q);

	result->print_info();
}
