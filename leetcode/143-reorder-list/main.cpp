#include <vector>
#include <string>
#include <logger.h>
#include <myleetcodestuff.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	void
	reorderList(ListNode *head)
	{
		ListNode *slow = head, *fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *rightPart = reverseList(slow->next);
		slow->next = nullptr;

		ListNode *leftPart = head;

		while (rightPart)
		{
			ListNode *leftTmp = leftPart->next;
			ListNode *rightTmp = rightPart->next;

			leftPart->next = rightPart;
			rightPart->next = leftTmp;

			leftPart = leftTmp;
			rightPart = rightTmp;
		}
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
		}
		return prev;
	}
};

int
main()
{
	ListNode *head = newLinkedList(vector<int>{ 1, 2, 3, 67, 5, 6 });
	Solution().reorderList(head);
	head->print_info();
}
