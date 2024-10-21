#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	vector<int>
	twoSum(vector<int> &numbers, int target)
	{
		int l = 0, r = numbers.size() - 1;
		while (l < r)
		{
			int currSum = numbers[l] + numbers[r];

			if (currSum == target)
				return vector<int>{ l + 1, r + 1 };

			if (currSum > target)
				r--;
			else
				l++;
		}

		return {};
	}
};

int
main()
{
	vector<int> numbers = { 2, 3, 4 };
	int target = 6;
	l.INFO(Solution().twoSum(numbers, target));
}
