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

	vector<vector<int>> valids;

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

		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (mapSet[nums[i]].find(nums[j]) == mapSet[nums[i]].end())
				{
					goto next_line;
				}
			}
		}

		valids.push_back(nums);

	next_line:
		continue;
	}

	int res = 0;
	for (auto &valid : valids)
	{
		int mid = valid.size() / 2;
		res += valid[mid];
	}

	l.DEBUG(res);
}
