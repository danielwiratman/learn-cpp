#include <algorithm>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	findMin(vector<int> &nums)
	{
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) / 2;

			if (nums.at(mid) > nums.at(right))
				left = mid + 1;
			else
				right = mid;
		}

		return nums.at(left);
	}
};

int
main()
{
	vector<int> nums = { 4, 5, 1, 2, 3 };
	l.INFO(Solution().findMin(nums));
}
