#include <unordered_set>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	bool
	checkInclusion(string s1, string s2)
	{
		if (s1.size() > s2.size())
			return false;

		vector<char> s1FreqVec(26, 0);
		for (auto &ch : s1)
			s1FreqVec[ch - 'a']++;

		int left = 0, right = s1.size() - 1;

		vector<char> windowFreqVec(26, 0);
		for (int i = 0; i < s1.size(); i++)
			windowFreqVec[s2.at(i) - 'a']++;

		while (right < s2.size())
		{
			if (s1FreqVec == windowFreqVec)
				return true;

			windowFreqVec[s2.at(left) - 'a']--;

			left++;
			right++;

			if (right < s2.size())
				windowFreqVec[s2.at(right) - 'a']++;
		}

		return false;
	}
};

int
main()
{
	string s1 = "abc", s2 = "ccccbbbbaaaa";
	l.INFO(Solution().checkInclusion(s1, s2));
}
