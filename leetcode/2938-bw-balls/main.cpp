#include <string>

using namespace std;

class Solution
{
  public:
	long long
	minimumSteps(string s)
	{
		long long result = 0;
		long long count = 0;
		int n = s.size();

		for (int i = n - 1; i > -1; i--)
		{
			if (s[i] == '0')
			{
				count++;
			}
			else
			{
				result += count;
			}
		}

		return result;
	}
};

int
main()
{
	string s = "101";
	printf("%lld", Solution().minimumSteps(s));
}
