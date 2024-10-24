#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	characterReplacement(string s, int k)
	{
		int left = 0, right = 0, result = 0;
		vector<int> freqMap(26, 0);

		while (right < s.size())
		{
			freqMap[s.at(right) - 'A']++;

			int numReplacementsNeeded =
				right - left + 1 - *max_element(freqMap.begin(), freqMap.end());

			if (numReplacementsNeeded > k)
			{
				while (numReplacementsNeeded > k)
				{
					freqMap[s.at(left) - 'A']--;
					left++;
					numReplacementsNeeded =
						right - left + 1 -
						*max_element(freqMap.begin(), freqMap.end());
				}
			}

			result = max(result, right - left + 1);
			right++;
		}

		return result;
	}
};

int
main()
{
	string s = "ABABBB";
	int k = 1;
	l.INFO(Solution().characterReplacement(s, k));
}
