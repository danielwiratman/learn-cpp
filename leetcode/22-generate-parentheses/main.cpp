#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
	void
	dfs(vector<string> &result, string curr, int m, int n)
	{
		if (m == 0 && n == 0)
		{
			result.push_back(curr);
			return;
		}

		if (m > 0)
		{
			curr.push_back('(');
			dfs(result, curr, m - 1, n);
			curr.pop_back();
		}

		if (n > m)
		{
			curr.push_back(')');
			dfs(result, curr, m, n - 1);
			curr.pop_back();
		}
	}

  public:
	vector<string>
	generateParenthesis(int n)
	{
		vector<string> result;
		dfs(result, "", n, n);
		return result;
	}
};

int
main()
{
	int n = 3;
	l.INFO(Solution().generateParenthesis(n));
}
