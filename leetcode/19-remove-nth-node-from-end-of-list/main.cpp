#include <vector>
#include <string>
#include <logger.h>
#include <myleetcodestuff.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	ListNode *
	removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *curr = head, *delay = head;

		while (curr)
		{
			curr = curr->next;
			if (n < 0)
				delay = delay->next;
			n--;
		}

		if (n == 0)
			head = head->next;

		if (delay->next)
		{
			if (delay->next->next)
				delay->next = delay->next->next;
			else
				delay->next = nullptr;
		}

		return head;
	}
};

int
main()
{
	ListNode *head = newLinkedList(vector<int>{ 1 });
	int n = 1;
	Solution().removeNthFromEnd(head, n)->print_info();
}
