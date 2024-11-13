#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <string>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  private:
	int preorder_idx = 0;

	unordered_map<int, int> inorderMap;

	TreeNode *
	dfs(vector<int> &preorder, int l, int r)
	{
		if (l > r)
			return nullptr;

		TreeNode *root = new TreeNode(preorder[preorder_idx++]);
		int inorderMid = inorderMap[root->val];

		root->left = dfs(preorder, l, inorderMid - 1);
		root->right = dfs(preorder, inorderMid + 1, r);

		return root;
	}

  public:
	TreeNode *
	buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		for (int i = 0; i < inorder.size(); i++)
			inorderMap[inorder[i]] = i;

		return dfs(preorder, 0, preorder.size() - 1);
	}
};

class SolutionBad
{
  public:
	TreeNode *
	buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		if (preorder.empty() || inorder.empty())
			return nullptr;

		TreeNode *root = new TreeNode(preorder[0]);
		vector<int>::iterator inorderMidIt =
			find(inorder.begin(), inorder.end(), preorder[0]);
		int inorderMid = distance(inorder.begin(), inorderMidIt);

		vector<int> leftPre(preorder.begin() + 1,
							preorder.begin() + 1 + inorderMid);
		vector<int> leftIn(inorder.begin(), inorder.begin() + inorderMid);
		root->left = buildTree(leftPre, leftIn);

		vector<int> rightPre(preorder.begin() + 1 + inorderMid, preorder.end());
		vector<int> rightIn(inorder.begin() + 1 + inorderMid, inorder.end());
		root->right = buildTree(rightPre, rightIn);

		return root;
	}
};

int
main()
{
	vector<int> preorder = { 3, 9, 20, 15, 7 };
	vector<int> inorder = { 9, 3, 15, 20, 7 };
	TreeNode *root = Solution().buildTree(preorder, inorder);
	root->print_info();
}
