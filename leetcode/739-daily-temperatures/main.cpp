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
	}
};

int
main()
{
	vector<int> temperatures = { 73, 74, 75, 71, 69, 72, 76, 73 };
	l.INFO(Solution().dailyTemperatures(temperatures));
}
