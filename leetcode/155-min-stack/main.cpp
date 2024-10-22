#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class MinStack
{
	vector<int> data;
	vector<int> mins;

  public:
	MinStack() {}

	void
	push(int val)
	{
		data.push_back(val);

		if (mins.empty() || val <= mins[mins.size() - 1])
			mins.push_back(val);
	}

	void
	pop()
	{
		if (data[data.size() - 1] == mins[mins.size() - 1])
			mins.pop_back();
		data.pop_back();
	}

	int
	top()
	{
		return data.at(data.size() - 1);
	}

	int
	getMin()
	{
		return mins[mins.size() - 1];
	}
};

int
main()
{
	MinStack *obj = new MinStack();
	obj->push(0);
	obj->push(1);
	obj->push(0);
	l.INFO(obj->getMin());
	obj->pop();
	l.INFO(obj->getMin());
}
