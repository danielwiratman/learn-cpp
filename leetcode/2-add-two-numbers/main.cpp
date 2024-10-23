#include <vector>
#include <string>
#include <logger.h>
#include "myleetcodestuff.h"

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	ListNode *
	addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *curr1 = l1, *curr2 = l2;

		int carry = 0;

		ListNode *resultHead = nullptr, *currResult = nullptr;

		while (curr1 || curr2)
		{
			int result = 0;

			if (curr1 && curr2)
				result = curr1->val + curr2->val + carry;
			else if (curr1 && !curr2)
				result = curr1->val + carry;
			else if (!curr1 && curr2)
				result = curr2->val + carry;

			carry = 0;

			if (result > 9)
			{
				carry = result / 10;
				result = result % 10;
			}

			if (!resultHead)
			{
				resultHead = new ListNode(result);
				currResult = resultHead;
			}
			else
			{
				currResult->next = new ListNode(result);
				currResult = currResult->next;
			}

			if (curr1)
				curr1 = curr1->next;
			if (curr2)
				curr2 = curr2->next;
		}

		if (carry)
			currResult->next = new ListNode(carry);

		return resultHead;
	}
};

int
main()
{
	ListNode *l1 = newLinkedList(vector<int>{ 9, 9, 9, 9, 9, 9, 9 });
	ListNode *l2 = newLinkedList(vector<int>{ 9, 9, 9, 9 });

	Solution().addTwoNumbers(l1, l2)->print_info();
}
