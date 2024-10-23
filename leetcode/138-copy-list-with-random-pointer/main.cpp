#include <cinttypes>
#include <unordered_map>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Node
{
  public:
	int val;
	Node *next;
	Node *random;

	Node(int _val)
	{
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution
{
  public:
	Node *
	copyRandomList(Node *head)
	{
		unordered_map<Node *, Node *> hMap;

		// first pass, for every node in existing, create the equivalent node in
		// hMap
		Node *curr = head;
		while (curr)
		{
			hMap[curr] = new Node(curr->val);
			curr = curr->next;
		}

		// second pass, for every node in existing, assign the random and next
		// for the equivalent node
		curr = head;
		while (curr)
		{
			hMap[curr]->next = hMap[curr->next];
			hMap[curr]->random = hMap[curr->random];
			curr = curr->next;
		}

		return hMap[head];
	}
};

// Interweaving nodes method.. so the deepcopy is weaved into the original node
// and then we reiterate and skip every other node
class Solution2
{
  public:
	Node *
	copyRandomList(Node *head)
	{
		if (!head)
			return nullptr;

		Node *curr = head;
		while (curr)
		{
			Node *newNode = new Node(curr->val);
			newNode->next = curr->next;
			curr->next = newNode;
			curr = newNode->next;
		}

		curr = head;
		while (curr)
		{
			// the random of the equivalent new node (curr' next is equivalent
			// new node curr's next's randome is equivalent new node's random is
			// the current's random's next which is the current random's
			// equivalent new node)
			if (curr->random)
				curr->next->random = curr->random->next;

			curr = curr->next->next;
		}

		Node *newHead = head->next, *currNew = newHead;
		curr = head;
		while (curr)
		{
			curr->next = curr->next->next;
			if (currNew->next)
				currNew->next = currNew->next->next;
			curr = curr->next;
			currNew = currNew->next;
		}

		return newHead;
	}
};

int
main()
{
	vector<pair<int, int>> data = {
		{ 7, -1 }, { 13, 0 }, { 11, 4 }, { 10, 2 }, { 1, 0 }
	};

	int n = data.size();
	vector<Node *> nodeData(n);

	for (int i = 0; i < n; i++)
		nodeData.at(i) = new Node(data.at(i).first);

	for (int i = 0; i < n; i++)
	{
		if (i != n - 1)
			nodeData.at(i)->next = nodeData.at(i + 1);
		if (data.at(i).second > -1)
			nodeData.at(i)->random = nodeData.at(data.at(i).second);
	}

	Node *head = nodeData.at(0), *curr = head;
	// while (curr)
	// {
	// 	l.INFO("val", curr->val);
	// 	if (curr->random)
	// 		l.INFO("random", curr->random->val);
	// 	curr = curr->next;
	// }

	Node *solution = Solution2().copyRandomList(head);
}
