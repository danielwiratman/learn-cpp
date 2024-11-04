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
	isSameTree(TreeNode *p, TreeNode *q)
	{
		if (!p && !q)
			return true;

		if ((!p && q) || (p && !q))
			return false;

		if (p->val != q->val)
			return false;

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};

int
main()
{
	TreeNode *p = newBinaryTree({ 1, 2, 3, 4 });
	TreeNode *q = newBinaryTree({ 1, 2, 3 });

	l.INFO(Solution().isSameTree(p, q));
}
