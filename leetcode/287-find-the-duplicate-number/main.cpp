#include <algorithm>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

// INVALID SOLUTION
// Just read that one of the requirements is to not modify the nums array.
// Basically means SORTING IS ILLEGAL
class SolutionWrong
{
  public:
	int
	findDuplicate(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());

		int curr = 0;

		for (auto &num : nums)
		{
			if (num == curr)
				return num;
			curr = num;
		}

		return -1;
	}
};

// linked list method
// It uses the law that if there is cycle in linked list, fast and slow pointer
// will meet
// This solution works because the actual is between 1 and the length
// of the array
//
// Reference on this: learn Floyd's Tortoise and Hare algorithm
//
// NeetCode thinks this problem is bad, because if you don't know Floyd's algo
// you screwed. He even thinks this should be considered hard.
class Solution
{
  public:
	int
	findDuplicate(vector<int> &nums)
	{
		int slow = nums.at(0), fast = nums.at(0);
		do
		{
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);

		slow = nums[0];
		while (slow != fast)
		{
			slow = nums[slow];
			fast = nums[fast];
		}

		return slow;
	}
};

int
main()
{
	vector<int> nums = { 2, 5, 9, 6, 9, 3, 8, 9, 7, 1 };
	l.INFO(Solution().findDuplicate(nums));
}
