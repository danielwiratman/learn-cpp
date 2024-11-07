#pragma once

#include <climits>
#include <cmath>
#include <iomanip>
#include <logger.h>
#include <queue>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

	void
	print_info()
	{
		vector<int> nums;
		ListNode *curr = this;
		while (curr)
		{
			nums.push_back(curr->val);
			curr = curr->next;
		}
		Logger::get().INFO(nums);
	}
};

inline ListNode *
newLinkedList(vector<int> nums)
{
	ListNode *head = nullptr, *curr = nullptr;

	for (int i = 0; i < nums.size(); i++)
	{
		if (head == nullptr)
		{
			head = new ListNode(nums[i]);
			curr = head;
		}
		else
		{
			curr->next = new ListNode(nums[i]);
			curr = curr->next;
		}
	}
	return head;
}

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

	void
	print_info()
	{
		vector<int> nums;
		queue<TreeNode *> q;
		q.push(this);

		while (!q.empty())
		{
			TreeNode *curr = q.front();
			q.pop();

			if (curr)
			{
				nums.push_back(curr->val);
				q.push(curr->left);
				q.push(curr->right);
			}
			else
				nums.push_back(INT_MIN);
		}

		while (!nums.empty() && nums.back() == INT_MIN)
			nums.pop_back();

		Logger::get().INFO(nums);
	}
};

inline TreeNode *
newBinaryTree(vector<int> nums)
{
	if (nums.size() == 0)
		return nullptr;

	TreeNode *root = new TreeNode(nums[0]);
	queue<TreeNode *> q;

	q.push(root);
	int i = 1;

	while (i < nums.size())
	{
		TreeNode *curr = q.front();
		q.pop();

		if (i < nums.size() && nums[i] != INT_MIN)
		{
			curr->left = new TreeNode(nums[i]);
			q.push(curr->left);
		}
		i++;

		if (i < nums.size() && nums[i] != INT_MIN)
		{
			curr->right = new TreeNode(nums[i]);
			q.push(curr->right);
		}
		i++;
	}

	return root;
}

// the words insert level order, doesnt imply that nodes are constructed in
// insert order.. i mean like it drills down the left subtree first right..
// for example if input is 1 2 3 4 5, then 1 2 then 4 then 5 then 3. The
// level order implies the actual parameter of the function.. it constructs
// a tree FROM a level order traversed array!!!!
inline TreeNode *
insertLevelOrder(vector<int> nums, TreeNode *root, int i, int n)
{
	if (i < n)
	{
		TreeNode *tmp = new TreeNode(nums.at(i));
		root = tmp;
		root->left = insertLevelOrder(nums, root->left, 2 * i + 1, n);
		root->right = insertLevelOrder(nums, root->right, 2 * i + 2, n);
	}
	return root;
}

inline TreeNode *
_recursive_newBinaryTree(vector<int> nums)
{
	return insertLevelOrder(nums, nullptr, 0, nums.size());
}
