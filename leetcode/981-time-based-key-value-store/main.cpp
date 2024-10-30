#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class TimeMap
{
	unordered_map<string, vector<pair<int, string>>> data;

  public:
	TimeMap() {}

	void
	set(string key, string value, int timestamp)
	{
		data[key].push_back(make_pair(timestamp, value));
	}

	string
	get(string key, int timestamp)
	{
		if (data.find(key) == data.end())
			return "";

		const vector<pair<int, string>> &timestampValuePairs = data[key];

		int left = 0, right = timestampValuePairs.size() - 1;

		if (timestamp < timestampValuePairs.at(0).first)
			return "";

		while (left <= right)
		{
			int mid = left + (right - left) / 2;

			if (timestampValuePairs[mid].first <= timestamp)
				left = mid + 1;
			else
				right = mid - 1;
		}

		return timestampValuePairs[right].second;
	}
};

int
main()
{
	TimeMap timeMap = TimeMap();
	timeMap.set("love", "high", 10);
	timeMap.set("love", "low", 20);
	l.INFO(timeMap.get("love", 5));
	l.INFO(timeMap.get("love", 10));
	l.INFO(timeMap.get("love", 15));
	l.INFO(timeMap.get("love", 20));
	l.INFO(timeMap.get("love", 25));
}
