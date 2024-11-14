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
	permute(vector<int> &nums)
	{
		vector<vector<int>> result;
		vector<int> data;
		dfs(data, nums, result);
		return result;
	}

  private:
	void
	dfs(vector<int> &data, vector<int> &remain, vector<vector<int>> &result)
	{
		if (remain.empty())
		{
			result.push_back(data);
			return;
		}

		for (int i = 0; i < remain.size(); i++)
		{
			vector<int> temp = remain;
			data.push_back(temp[i]);
			temp.erase(temp.begin() + i);
			dfs(data, temp, result);
			data.pop_back();
		}
	}
};

int
main()
{
	vector<int> nums = { 1, 2, 3 };
	l.INFO(Solution().permute(nums));
}
