#include <stack>
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
};

class Solution
{
  public:
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

	// ListNode *
	// reverseListWithStack(ListNode *head)
	// {
	// 	if (head == nullptr)
	// 		return nullptr;
	//
	// 	stack<int> st;
	//
	// 	ListNode *curr = head;
	// 	while (curr)
	// 	{
	// 		st.push(curr->val);
	// 		curr = curr->next;
	// 	}
	//
	// 	ListNode *result = new ListNode(st.top());
	// 	st.pop();
	//
	// 	curr = result;
	// 	while (!st.empty())
	// 	{
	// 		curr->next = new ListNode(st.top());
	// 		st.pop();
	// 		curr = curr->next;
	// 	}
	//
	// 	return result;
	// }
};

int
main()
{
	l.INFO(Solution());
}
