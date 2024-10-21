#include <algorithm>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &logger = Logger::get();

class Solution
{
  public:
	vector<vector<int>>
	threeSum(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());

		vector<vector<int>> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			int l = i + 1, r = nums.size() - 1;
			int target = -nums[i];

			while (l < r)
			{
				int currSum = nums[l] + nums[r];
				if (currSum == target)
				{
					result.push_back(vector<int>{ nums[i], nums[l], nums[r] });
					while (l < r && nums[l] == nums[l + 1])
						l++;
					while (l < r && nums[r] == nums[r - 1])
						r--;
				}
				if (currSum > target)
					r--;
				else
					l++;
			}
		}

		return result;
	}
};

int
main()
{
	vector<int> nums = {
		0,
		0,
		0,
		0,
	};
	logger.INFO(Solution().threeSum(nums));
}
