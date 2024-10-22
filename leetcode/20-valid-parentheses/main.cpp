#include <stack>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	bool
	isValid(string s)
	{
		stack<char> st;
		for (auto &ch : s)
		{
			if (ch == '(' || ch == '{' || ch == '[')
				st.push(ch);
			else
			{
				if (st.size() == 0)
					return false;
				if (ch == ')' && st.top() != '(')
					return false;
				if (ch == '}' && st.top() != '{')
					return false;
				if (ch == ']' && st.top() != '[')
					return false;
				st.pop();
			}
		}
		return st.size() == 0;
	}
};

int
main()
{
	string s = "((";
	l.INFO(Solution().isValid(s));
}
