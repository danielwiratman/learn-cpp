#include <chrono>
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
	search(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (nums.at(mid) == target)
				return mid;

			if (nums.at(mid) > nums.at(right))
			{
				if (nums.at(mid) > target)
					left = mid + 1;
				else
					right = mid - 1;
			}
			else
			{
				if (nums.at(mid) > target)
					right = mid - 1;
				else
					left = mid + 1;
			}
		}

		return -1;
	}
};

int
main()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	int target = 3;
	l.INFO(Solution().search(nums, target));
}
