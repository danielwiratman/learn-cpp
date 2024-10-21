#include <algorithm>
#include <unordered_set>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	longestConsecutive(vector<int> &nums)
	{
		if (nums.size() == 0)
			return 0;

		unordered_set<int> hSet;
		vector<int> numsUnique;

		for (auto &num : nums)
		{
			if (hSet.find(num) == hSet.end())
				numsUnique.push_back(num);

			hSet.insert(num);
		}

		sort(numsUnique.begin(), numsUnique.end());

		int maxResult = 0;
		int result = 1;

		for (int i = 1; i < numsUnique.size(); i++)
		{
			int diff = numsUnique[i] - numsUnique[i - 1];
			if (diff == 1)
				result++;
			else
			{
				maxResult = max(maxResult, result);
				result = 1;
			}
		}

		maxResult = max(maxResult, result);

		return maxResult;
	}
};

int
main()
{
	vector<int> nums = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
	l.INFO(Solution().longestConsecutive(nums));
}
