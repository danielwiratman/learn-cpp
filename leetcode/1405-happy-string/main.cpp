#include <cstdio>
#include <queue>
#include <string>

using namespace std;

class Solution
{
  public:
	string
	longestDiverseString(int a, int b, int c)
	{
		priority_queue<pair<int, char>> pq;
		string result;

		if (a > 0)
			pq.push(make_pair(a, 'a'));

		if (b > 0)
			pq.push(make_pair(b, 'b'));

		if (c > 0)
			pq.push(make_pair(c, 'c'));

		while (!pq.empty())
		{
			auto [mostManyCharCount, mostManyChar] = pq.top();
			pq.pop();

			if (result.size() > 1 &&
				result.at(result.size() - 1) == mostManyChar &&
				result.at(result.size() - 2) == mostManyChar)
			{
				if (pq.empty())
				{
					break;
				}

				auto [secondMostManyCharCount, secondMostManyChar] = pq.top();
				pq.pop();

				result.push_back(secondMostManyChar);
				secondMostManyCharCount--;

				if (secondMostManyCharCount > 0)
				{
					pq.push(
						make_pair(secondMostManyCharCount, secondMostManyChar));
				}

				pq.push(make_pair(mostManyCharCount, mostManyChar));
			}
			else
			{
				result.push_back(mostManyChar);
				mostManyCharCount--;

				if (mostManyCharCount > 0)
				{
					pq.push(make_pair(mostManyCharCount, mostManyChar));
				}
			}
		}

		return result;
	}
};

int
main()
{
	int a = 7, b = 1, c = 0;
	puts(Solution().longestDiverseString(a, b, c).c_str());
	return 0;
}
