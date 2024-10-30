#pragma once

#include <logger.h>

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
	traverse(vector<int> &nums, TreeNode *node)
	{
		if (node == nullptr)
			return;
		nums.push_back(node->val);
		traverse(nums, node->left);
		traverse(nums, node->right);
	}

	void
	print_info()
	{
		vector<int> nums;
		traverse(nums, this);
		Logger::get().INFO(nums);
	}
};

inline TreeNode *
newBinaryTree(vector<int> nums)
{
	TreeNode *root = nullptr, *curr = nullptr;

	for (int i = 0; i < nums.size(); i++)
	{
		if (root == nullptr)
		{
			root = new TreeNode(nums.at(i));
			curr = root;
		}
		else
		{
			if (curr->left == nullptr)
			{
				curr->left = new TreeNode(nums.at(i));
			}
			else
			{
				curr->right = new TreeNode(nums.at(i));
			}
		}
	}

	return root;
}
