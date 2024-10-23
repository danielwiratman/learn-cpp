#include <unordered_set>
#include <vector>
#include <string>
#include <logger.h>
#include <myleetcodestuff.h>

using namespace std;

auto &l = Logger::get();

// Hash Set method, performance On but space also On
class Solution
{
  public:
	bool
	hasCycle(ListNode *head)
	{
		unordered_set<ListNode *> hSet;

		ListNode *curr = head;
		while (curr)
		{
			if (hSet.find(curr) != hSet.end())
				return true;

			hSet.insert(curr);
			curr = curr->next;
		}

		return false;
	}
};

// Fast Slow pointer (Two pointers method)
// It may seem that fast can skip the slow, but after trying on paper, indeed at
// a point fast will always catch up with slow however counterintuitive it may
// seem.
class Solution2
{
  public:
	bool
	hasCycle(ListNode *head)
	{
		ListNode *slow = head, *fast = head;

		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;

			if (slow == fast)
				return true;
		}
		return false;
	}
};

int
main()
{
}
