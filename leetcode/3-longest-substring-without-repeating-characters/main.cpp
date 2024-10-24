#include <unordered_set>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	lengthOfLongestSubstring(string s)
	{
		unordered_set<char> hSet;
		int left = 0, right = 0, result = 0;

		while (right < s.size())
		{
			if (hSet.find(s.at(right)) != hSet.end())
			{
				while (s.at(left) != s.at(right))
				{
					hSet.erase(s.at(left));
					left++;
				}
				left++;
			}
			hSet.insert(s.at(right));

			if (hSet.size() > result)
				result = hSet.size();

			right++;
		}

		return result;
	}
};

int
main()
{
	string s = "abcabcbb";
	l.INFO(Solution().lengthOfLongestSubstring(s));
}
