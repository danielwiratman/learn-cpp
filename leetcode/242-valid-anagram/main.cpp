#include <cstdio>
#include <stdatomic.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  public:
	bool
	isAnagram(string s, string t)
	{
		unordered_map<char, int> mapCharToCount;
		for (char &ch : s)
			mapCharToCount[ch]++;

		for (char &ch : t)
		{
			auto findIdx = mapCharToCount.find(ch);
			if (findIdx != mapCharToCount.end())
				mapCharToCount[ch]--;
			else
				return false;
			;
		}

		for (auto &[_, value] : mapCharToCount)
		{
			if (value != 0)
				return false;
		}

		return true;
	}
};

int
main()
{
	string s = "rec", t = "cer";
	printf("%b\n", Solution().isAnagram(s, t));
}
