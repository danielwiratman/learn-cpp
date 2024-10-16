#include <string>

using namespace std;

class Solution
{
  public:
	int
	minAddToMakeValid(string s)
	{
		int stillOpen = 0;
		int result = 0;

		for (auto &ch : s)
		{
			if (ch == '(')
				stillOpen++;
			else
			{
				if (stillOpen > 0)
					stillOpen--;
				else
					result++;
			}
		}

		result += stillOpen;
		return result;
	}
};

int
main()
{
	string s = "()))((";
	printf("%d", Solution().minAddToMakeValid(s));
}
