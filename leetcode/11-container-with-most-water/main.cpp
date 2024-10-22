#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &logger = Logger::get();

class Solution
{
  public:
	int
	maxArea(vector<int> &height)
	{
		int result = 0;
		int l = 0, r = height.size() - 1;

		while (l < r)
		{
			int currArea = (r - l) * min(height[l], height[r]);
			result = max(result, currArea);

			if (height[l] <= height[r])
				l++;
			else
				r--;
		}

		return result;
	}
};

int
main()
{
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	logger.INFO(Solution().maxArea(height));
}
