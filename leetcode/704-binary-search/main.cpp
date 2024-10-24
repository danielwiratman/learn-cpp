#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	search(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (nums.at(mid) == target)
				return mid;

			if (nums.at(mid) < target)
				left = mid + 1;
			else if (nums.at(mid) > target)
				right = mid - 1;
		}

		return -1;
	}
};

int
main()
{
	vector<int> nums = { -1, 0, 3, 5, 9, 12 };
	int target = 0;
	l.INFO(Solution().search(nums, target));
}
