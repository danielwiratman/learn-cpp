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
		stack<int> st;
		vector<int> result(temperatures.size(), 0);

		for (int i = 0; i < temperatures.size(); i++)
		{
			while (!st.empty() && temperatures[st.top()] < temperatures[i])
			{
				result[st.top()] = i - st.top();
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
