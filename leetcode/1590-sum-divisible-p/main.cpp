#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

class Solution
{
  public:
	int
	minSubarray(vector<int> &nums, int p)
	{
		sort(nums.begin(), nums.end());
	}
};

int
main()
{
	vector<int> nums = { 3, 1, 4, 2 };
	int p = 6;

	printf("%d", Solution().minSubarray(nums, p));
}
