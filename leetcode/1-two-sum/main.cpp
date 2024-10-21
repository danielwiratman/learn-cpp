#include <cstdio>
#include <unordered_map>
#include <vector>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	vector<int>
	twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> hMap;
		for (int i = 0; i < nums.size(); i++)
		{
			int remain = target - nums[i];
			if (hMap.find(remain) != hMap.end())
			{
				return { i, hMap[remain] };
			}

			hMap[nums[i]] = i;
		}

		return {};
	}
};

int
main()
{
	vector<int> nums = { 3, 2, 4 };
	int target = 6;
	l.INFO(Solution().twoSum(nums, target));
}
