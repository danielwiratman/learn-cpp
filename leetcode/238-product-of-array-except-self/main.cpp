#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	vector<int>
	productExceptSelf(vector<int> &nums)
	{
		vector<int> left(nums.size());
		left[0] = 1;
		vector<int> right(nums.size());
		right[nums.size() - 1] = 1;

		for (int i = 1; i < nums.size(); i++)
			left[i] = nums[i - 1] * left[i - 1];

		for (int i = nums.size() - 2; i > -1; i--)
			right[i] = nums[i + 1] * right[i + 1];

		vector<int> result(nums.size());
		for (int i = 0; i < nums.size(); i++)
			result[i] = left[i] * right[i];

		return result;
	}
};

int
main()
{
	vector<int> nums = { -1, 1, 0, -3, 3 };
	l.INFO(Solution().productExceptSelf(nums));
}
