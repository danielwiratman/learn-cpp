#include <string>

using namespace std;

class Solution
{
  public:
	int
	minSwaps(string s)
	{
		int numOpen = 0, numClose = 0;
		int result = 0;

		for (auto &ch : s)
		{
			if (ch == ']')
				numClose++;
			else
				numOpen++;

			if (numClose > numOpen)
			{
				result++;
				numClose--;
				numOpen++;
			}
		}

		return result;
	}
};

int
main()
{
	string s = "][][";
	printf("%d", Solution().minSwaps(s));
}
