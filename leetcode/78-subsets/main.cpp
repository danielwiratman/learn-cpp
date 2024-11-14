#include <algorithm>
#include <vector>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	vector<vector<int>>
	subsets(vector<int> &nums)
	{
		vector<vector<int>> result;
		dfs(0, {}, nums, result);
		return result;
	}

  private:
	void
	dfs(int numsIdx, vector<int> data, vector<int> nums,
		vector<vector<int>> &result)
	{
		result.push_back(data);

		// iterate over remaining nums
		for (int i = numsIdx; i < nums.size(); i++)
		{
			data.push_back(nums[i]);
			dfs(i + 1, data, nums, result);
			data.pop_back();
		}
	}
};

int
main()
{
	vector<int> nums = { 1, 2, 3 };
	l.INFO(Solution().subsets(nums));
}
