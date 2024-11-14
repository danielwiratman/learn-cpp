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
	combinationSum(vector<int> &candidates, int target)
	{
		vector<vector<int>> result;
		vector<int> data;
		dfs(0, data, candidates, target, result);
		return result;
	}

  private:
	void
	dfs(int candIdx, vector<int> &data, vector<int> &candidates, int target,
		vector<vector<int>> &result)
	{
		if (target < 0)
			return;

		if (target == 0)
			result.push_back(data);

		for (int i = candIdx; i < candidates.size(); i++)
		{
			int cand = candidates[i];
			data.push_back(cand);
			dfs(i, data, candidates, target - cand, result);
			data.pop_back();
		}
	}
};

int
main()
{
	vector<int> candidates = { 2, 3, 6, 7 };
	int target = 7;
	l.INFO(Solution().combinationSum(candidates, target));
}
