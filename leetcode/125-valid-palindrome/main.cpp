#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
	const string ALPHA_NUMERIC = "abcdefghijklmnopqrstuvwxyz0123456789";

  public:
	bool
	isPalindrome(string s)
	{
		string sterileString;
		for (int i = s.size() - 1; i > -1; i--)
			if (ALPHA_NUMERIC.find(tolower(s[i])) != string::npos)
				sterileString.push_back(tolower(s[i]));

		int leftptr = 0, rightptr = sterileString.size() - 1;

		while (leftptr < rightptr)
		{
			if (sterileString[leftptr] == sterileString[rightptr])
			{
				leftptr++;
				rightptr--;
			}
			else
				return false;
		}

		return true;
	}
};

int
main()
{
	string s = "A man, a plan, a canal: Panama";
	l.INFO(Solution().isPalindrome(s));
}
