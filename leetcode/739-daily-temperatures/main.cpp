#include <stack>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	vector<int>
	dailyTemperatures(vector<int> &temperatures)
	{
		vector<int> result(temperatures.size(), 0);
		stack<int> st;

		for (size_t i = 0; i < temperatures.size(); i++)
		{
			while (!st.empty() &&
				   temperatures.at(i) > temperatures.at(st.top()))
			{
				result.at(st.top()) = i - st.top();
				st.pop();
			}
			st.push(i);
		}

		return result;
	}
};

int
main()
{
	vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	l.INFO(Solution().dailyTemperatures(temperatures));
}
