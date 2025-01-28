#include <algorithm>
#include <fstream>
#include "logger.h"
#include <unordered_map>
#include <unordered_set>

using namespace std;

Logger &l = Logger::get();

vector<string>
string_split(string s, char delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = s.find(delim, prev);
		if (pos == string::npos)
			pos = s.length();
		string token = s.substr(prev, pos - prev);
		if (!token.empty())
			tokens.push_back(token);
		prev = pos + 1;
	} while (pos < s.length() && prev < s.length());
	return tokens;
}

int
main()
{
	ifstream file("input.txt");

	unordered_map<int, unordered_set<int>> mapSet;

	vector<vector<int>> invalids;

	string line;
	while (getline(file, line) && line.size() != 0)
	{
		vector<string> twoNums = string_split(line, '|');
		int numA = stoi(twoNums[0]);
		int numB = stoi(twoNums[1]);

		mapSet[numA].insert(numB);
	}

	while (getline(file, line))
	{
		vector<string> rawNums = string_split(line, ',');
		vector<int> nums;
		for (auto &numStr : rawNums)
			nums.push_back(stoi(numStr));

		bool will_add = false;

		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (mapSet[nums[i]].find(nums[j]) != mapSet[nums[i]].end())
					continue;

				will_add = true;

				while (mapSet[nums[i]].find(nums[j]) == mapSet[nums[i]].end())
				{
					swap(nums[i], nums[j]);
				}
			}
		}

		if (will_add)
			invalids.push_back(nums);
	}

	int res = 0;
	for (int i = 0; i < invalids.size(); i++)
	{
		l.DEBUG("Invalid", invalids[i]);
		int mid = invalids[i].size() / 2;
		res += invalids[i][mid];
	}

	l.DEBUG(res);
}
