#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

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
		l.INFO(nums);
	}
};

ListNode *
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

class Solution
{
	ListNode *
	getMidpoint(ListNode *head)
	{
		ListNode *slow = head, *fast = head;
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}

	ListNode *
	reverseList(ListNode *head)
	{
		ListNode *prev = nullptr, *curr = head, *next = nullptr;
		while (curr)
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		};

		return prev;
	}

  public:
	void
	reorderList(ListNode *head)
	{
		ListNode *midNode = getMidpoint(head);
		midNode = reverseList(midNode);

		ListNode *curr1 = head, *next1 = nullptr;
		ListNode *curr2 = midNode, *next2 = nullptr;

		curr1->print_info();
		curr2->print_info();

		while (curr1)
		{
			next1 = curr1->next;
			curr1->next = curr2;
			curr2->next = next1;
			curr1 = next1;
		}

		head->print_info();
	}
};

int
main()
{
	ListNode *head = newLinkedList(vector<int>{ 1, 2, 3, 4, 5 });
	Solution().reorderList(head);
}
