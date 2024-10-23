#include <algorithm>
#include <stack>
#include <thread>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	carFleet(int target, vector<int> &position, vector<int> &speed)
	{
		vector<pair<int, int>> data;
		size_t n = position.size();

		for (size_t i = 0; i < n; i++)
			data.emplace_back(make_pair(position.at(i), speed.at(i)));

		sort(data.begin(),
			 data.end(),
			 [](const pair<int, int> &a, const pair<int, int> &b) {
				 return a.first > b.first;
			 });

		stack<double> st;
		for (size_t i = 0; i < n; i++)
		{
			int a = data.at(i).first, b = data.at(i).second;
			double timeToTarget = (double) (target - a) / b;
			if (st.empty() || timeToTarget > st.top())
				st.push(timeToTarget);
		}

		return st.size();
	}
};

int
main()
{
	int target = 12;
	vector<int> position = { 10, 8, 0, 5, 3 }, speed = { 2, 4, 1, 1, 3 };
	l.INFO(Solution().carFleet(target, position, speed));
}
