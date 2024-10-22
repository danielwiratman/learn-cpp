#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
	bool
	isNum(string &s)
	{
		if (s.empty())
			return false;

		size_t firstCharIdx = 0;

		if (s[0] == '-')
		{
			if (s.size() == 1)
				return false;
			else
				firstCharIdx = 1;
		}

		for (int i = firstCharIdx; i < s.size(); i++)
		{
			if (!isdigit(s.at(i)))
				return false;
		}

		return true;
	}

  public:
	int
	evalRPN(vector<string> &tokens)
	{
		stack<int> st;
		for (string &s : tokens)
		{
			if (isNum(s))
				st.push(stoi(s));
			else
			{
				int val2 = st.top();
				st.pop();
				int val1 = st.top();
				st.pop();

				int result;

				if (s == "+")
					result = val1 + val2;
				else if (s == "-")
					result = val1 - val2;
				else if (s == "*")
					result = val1 * val2;
				else if (s == "/")
					result = val1 / val2;

				st.push(result);
			}
		}
		if (st.size() == 1)
			return st.top();
		else
			return 0;
	}
};

int
main()
{
	vector<string> tokens = { "10", "6", "9",  "3", "+", "-11", "*",
							  "/",	"*", "17", "+", "5", "+" };
	l.INFO(Solution().evalRPN(tokens));
}
