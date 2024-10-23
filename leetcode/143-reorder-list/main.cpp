#include <vector>
#include <string>
#include <logger.h>
#include <myleetcodestuff.h>

using namespace std;

auto &l = Logger::get();

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
		ListNode *secondHalf = reverseList(midNode->next);
		midNode->next = nullptr;

		ListNode *firstHalf = head;
		while (secondHalf)
		{
			ListNode *tmp1 = firstHalf->next;
			ListNode *tmp2 = secondHalf->next;

			firstHalf->next = secondHalf;
			secondHalf->next = tmp1;

			firstHalf = tmp1;
			secondHalf = tmp2;
		}

		head->print_info();
	}
};

int
main()
{
	ListNode *head = newLinkedList(vector<int>{ 1, 2, 3, 4, 5, 6 });
	Solution().reorderList(head);
}
