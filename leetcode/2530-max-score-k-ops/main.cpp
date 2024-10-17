#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
  public:
	long long
	maxKelements(vector<int> &nums, int k)
	{
		long long result = 0;

		priority_queue<int> maxHeap;

		for (auto &num : nums)
			maxHeap.push(num);

		int i = 0;
		while (i < k)
		{
			int extracted = maxHeap.top();
			maxHeap.pop();

			result += extracted;

			maxHeap.push(
				static_cast<int>(ceil(static_cast<double>(extracted) / 3)));

			i++;
		}

		return result;
	}
};

int
main()
{
	vector<int> nums = { 1, 10, 3, 3, 3 };
	int k = 3;
	printf("%lld", Solution().maxKelements(nums, k));
}
