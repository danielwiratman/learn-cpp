#include <algorithm>
#include <vector>
#include <string>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	vector<vector<int>>
	combinationSum2(vector<int> &candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		vector<int> curr;
		backtrack(0, curr, candidates, target, result);
		return result;
	}

  private:
	void
	backtrack(int minIdx, vector<int> &curr, vector<int> &candidates,
			  int target, vector<vector<int>> &result)
	{
		if (target == 0)
		{
			result.push_back(curr);
			return;
		}

		for (int i = minIdx; i < candidates.size(); i++)
		{
			if (i > minIdx && candidates[i] == candidates[i - 1])
				continue;

			if (candidates[i] > target)
				break;

			curr.push_back(candidates[i]);
			backtrack(i + 1, curr, candidates, target - candidates[i], result);
			curr.pop_back();
		}
	}
};

int
main()
{
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	int target = 8;
	l.INFO(Solution().combinationSum2(candidates, target));
}
