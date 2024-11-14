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
	subsetsWithDup(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> curr;
		backtrack(0, curr, nums, result);
		return result;
	}

  private:
	void
	backtrack(int minIdx, vector<int> &curr, vector<int> &remain,
			  vector<vector<int>> &result)
	{
		result.push_back(curr);
		vector<int> done;
		for (int i = minIdx; i < remain.size(); i++)
		{
			vector<int> temp = remain;
			if (find(done.begin(), done.end(), temp[i]) != done.end())
				continue;
			curr.push_back(temp[i]);
			done.push_back(temp[i]);
			temp.erase(temp.begin() + i);
			backtrack(i, curr, temp, result);
			curr.pop_back();
		}
	}
};

int
main()
{
	vector<int> nums = { 4, 4, 4, 1, 4 };
	l.INFO(Solution().subsetsWithDup(nums));
}
