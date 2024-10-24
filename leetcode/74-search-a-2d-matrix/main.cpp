#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	bool
	searchMatrix(vector<vector<int>> &matrix, int target)
	{
		int m = matrix.size(); // num rows
		for (int i = 0; i < m; i++)
		{
			if (binsearch(matrix.at(i), target))
				return true;
		}
		return false;
	}

	bool
	binsearch(vector<int> &nums, int target)
	{
		int left = 0, right = nums.size() - 1;

		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (nums.at(mid) == target)
				return true;
			else if (nums.at(mid) < target)
				left = mid + 1;
			else if (nums.at(mid) > target)
				right = mid - 1;
		}
		return false;
	}
};

int
main()
{
	vector<vector<int>> matrix = { { 1, 2, 5, 7 },
								   { 10, 11, 16, 20 },
								   { 23, 30, 34, 60 } };
	int target = 3;
	l.INFO(Solution().searchMatrix(matrix, target));
}
