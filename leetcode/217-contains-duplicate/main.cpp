#include <cstdio>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  public:
	bool
	containsDuplicate(vector<int> &nums)
	{
		unordered_set<int> hSet;
		for (int i = 0; i < nums.size(); i++)
		{
			if (hSet.find(nums[i]) != hSet.end())
			{
				return true;
			}
			hSet.insert(nums[i]);
		}
		return false;
	}
};

int
main()
{
	vector<int> nums = { 2, 3, 1 };
	printf("%b\n", Solution().containsDuplicate(nums));
}
