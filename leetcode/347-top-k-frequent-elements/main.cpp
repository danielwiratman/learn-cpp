#include <algorithm>
#include <unordered_map>
#include <vector>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	vector<int>
	topKFrequent(vector<int> &nums, int k)
	{
		unordered_map<int, int> numToCount;

		for (int &num : nums)
			numToCount[num]++;

		vector<vector<int>> pairs;
		for (auto &[key, value] : numToCount)
			pairs.push_back({ key, value });

		sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) {
			return a[1] > b[1];
		});

		vector<int> result;
		for (int i = 0; i < k; i++)
			result.push_back(pairs[i][0]);

		return result;
	}
};

int
main()
{
	vector<int> nums = { 1, 1, 1, 2, 2, 3 };
	int k = 2;
	l.INFO(Solution().topKFrequent(nums, k));
}
