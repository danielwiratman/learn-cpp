#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class Solution
{
  public:
	string
	decodeAtIndex(string s, int k)
	{
		long long currLen = 0;

		for (auto &ch : s)
		{
			if (isdigit(ch))
				currLen *= ctoi(ch);
			else
				currLen++;
		}

		for (int i = s.size() - 1; i > -1; i--)
		{
			char ch = s.at(i);

			k %= currLen;

			if (k == 0 && isalpha(ch))
				return string(1, ch);

			if (isdigit(ch))
				currLen /= ctoi(ch);
			else
				currLen--;
		}
		return "";
	}

	int
	ctoi(char c)
	{
		return c - '0';
	};
};

int
main()
{
	string s = "leet2code3";
	int k = 10;
	puts(Solution().decodeAtIndex(s, k).c_str());
}
