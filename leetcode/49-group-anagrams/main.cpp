#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	vector<vector<string>>
	groupAnagrams(vector<string> &strs)
	{
		unordered_map<string, vector<string>> hMap;

		for (auto &s : strs)
		{
			string sCopy = s;
			sort(sCopy.begin(), sCopy.end());
			hMap[sCopy].push_back(s);
		}

		vector<vector<string>> result;
		for (auto &[_, value] : hMap)
		{
			result.push_back(value);
		}

		return result;
	}
};

int
main()
{
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	l.INFO(Solution().groupAnagrams(strs));
}
