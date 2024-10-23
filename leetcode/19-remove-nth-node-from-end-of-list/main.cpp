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
		int listSize = 0;
		ListNode *curr = head;
		while (curr)
		{
			curr = curr->next;
			listSize++;
		}

		ListNode *result = new ListNode(head->val);
		curr = result;
		ListNode *currHead = head->next;
		for (int i = 1; i < listSize; i++)
		{
			curr->next = currHead;
		}

		l.INFO(listSize);
	}

	// ListNode *
	// removeNthFromEndUsingArray(ListNode *head, int n)
	// {
	// 	ListNode *curr = head;
	// 	vector<int> nums;
	//
	// 	while (curr)
	// 	{
	// 		nums.push_back(curr->val);
	// 		curr = curr->next;
	// 	}
	//
	// 	vector<int> resultVec;
	// 	for (int i = 0; i < nums.size(); i++)
	// 	{
	// 		if (i != nums.size() - n)
	// 			resultVec.push_back(nums.at(i));
	// 	}
	//
	// 	return newLinkedList(resultVec);
	// }
};

int
main()
{
	ListNode *head = newLinkedList(vector<int>{ 1, 2, 3, 4, 5 });
	int n = 2;
	Solution().removeNthFromEnd(head, n)->print_info();
}
