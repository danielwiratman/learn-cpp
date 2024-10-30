#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	search(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;

		// uses <= because we do count mid,
		// and if left = right, then mid = left = right
		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (nums.at(mid) == target)
				return mid;

			if (nums.at(mid) > nums.at(right))
			{
				// mid is more than right, which means left side of mid is
				// sorted, mean while right side has some turning point inside
				// it, making it unsorted.. so we put the nested if i nthe left
				// side, the side which is sorted, to get some certainty
				if (nums.at(left) <= target && target < nums.at(mid))
					right = mid - 1;
				else
					left = mid + 1;
			}
			else
			{
				// mid is less than right, which means right side of mid is
				// sorted, the turning point in the left side. Nested if is used
				// for the sorted side for certainty thats why we aim for right
				// side in nested if
				if (nums.at(mid) < target && target <= nums.at(right))
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return -1;
	}
};

int
main()
{
	vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
	int target = 0;
	l.INFO(Solution().search(nums, target));
}
