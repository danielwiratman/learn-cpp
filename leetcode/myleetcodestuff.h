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
