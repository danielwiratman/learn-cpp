#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
  public:
	void
	rotate(vector<int> &nums, int k)
	{
		vector<int> numsCopy = nums;

		k %= nums.size();

		for (int i = 0; i < nums.size(); i++)
		{
			int numsCopyIdx = nums.size() - k + i;
			numsCopyIdx %= nums.size();

			nums[i] = numsCopy[numsCopyIdx];
		}
	}
};

int
main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	Solution().rotate(nums, k);

	printf("[ ");
	for (auto &num : nums)
	{
		printf("%d ", num);
	}
	printf("]\n");
}
