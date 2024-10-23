#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right)
											: val(x), left(left), right(right)
	{
	}
};

class Solution
{
  public:
	TreeNode *
	replaceValueInTree(TreeNode *root)
	{
	}
};

int
main()
{
	l.INFO(Solution());
}
