#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
  public:
	int
	minGroups(vector<vector<int>> &intervals)
	{
		vector<pair<int, int>> events;
		for (auto &interval : intervals)
		{
			events.push_back({ interval.at(0), 1 });
			events.push_back({ interval.at(1) + 1, -1 });
		}

		sort(events.begin(), events.end());

		int concurrentEvents = 0;
		int result = 0;

		for (auto &[_, inc] : events)
		{
			concurrentEvents += inc;

			result = max(result, concurrentEvents);
		}

		return result;
	}
};

int
main()
{
	vector<vector<int>> intervals = {
		{ 5, 10 }, { 6, 8 }, { 1, 5 }, { 2, 3 }, { 1, 10 }
	};
	printf("%d", Solution().minGroups(intervals));
}
