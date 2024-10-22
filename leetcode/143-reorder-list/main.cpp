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
	void
	reorderList(ListNode *head)
	{
	}
};

int
main()
{
	l.INFO(Solution());
}
