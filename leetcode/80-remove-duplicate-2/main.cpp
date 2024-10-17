#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  public:
	int
	removeDuplicates(vector<int> &nums)
	{
		if (nums.size() < 3)
			return nums.size();

		int k = 2;
		for (int i = 2; i < nums.size(); i++)
		{
			if (nums[i] != nums[k - 2])
			{
				nums[k++] = nums[i];
			}
		}

		return k;
	}
};

int
main()
{
	vector<int> nums = { 1, 1, 1, 2, 2, 3 };
	printf("%d\n", Solution().removeDuplicates(nums));
	for (int i = 0; i < nums.size(); i++)
	{
		printf("%d ", nums[i]);
	}
}
