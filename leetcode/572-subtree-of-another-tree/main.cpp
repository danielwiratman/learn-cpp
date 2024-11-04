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
	isSubtree(TreeNode *root, TreeNode *subRoot)
	{
		if (!root)
			return false;

		if (isSameTree(root, subRoot))
			return true;

		return isSubtree(root->left, subRoot) ||
			   isSubtree(root->right, subRoot);
	}

  private:
	bool
	isSameTree(TreeNode *p, TreeNode *q)
	{
		if (!p && !q)
			return true;

		if ((!p && q) || (p && !q) || (p->val != q->val))
			return false;

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

int
main()
{
	TreeNode *root = newBinaryTree({ 3, 4, 5, 1, 2 });
	TreeNode *subRoot = newBinaryTree({ 4, 1, 2 });

	l.INFO(Solution().isSubtree(root, subRoot));
}
