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
	}
};

int
main()
{
	string s = "ABAB";
	int k = 2;
	l.INFO(Solution().characterReplacement(s, k));
}
