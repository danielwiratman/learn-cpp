#include <algorithm>
#include <iostream>
#include <logger.h>

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
	ifstream in("input.txt");
	if (!in)
	{
		l.ERROR("Could not open input.txt");
		return 1;
	}

	vector<int> leftNums;
	vector<int> rightNums;

	string line;
	while (getline(in, line))
	{
		vector<string> splits = string_split(line, ' ');
		if (splits.size() != 2)
		{
			l.ERROR("Invalid input");
			return 1;
		}

		int left = stoi(splits[0]);
		int right = stoi(splits[1]);

		leftNums.push_back(left);
		rightNums.push_back(right);
	}

	if (leftNums.size() != rightNums.size())
	{
		l.ERROR("Invalid input");
		return 1;
	}

	// sort(leftNums.begin(), leftNums.end());
	// sort(rightNums.begin(), rightNums.end());

	int res = 0;
	for (int i = 0; i < leftNums.size(); i++)
	{
		int count = 0;
		for (int rightNum : rightNums)
		{
			if (leftNums[i] == rightNum)
			{
				count++;
			}
		}

		res += count * leftNums[i];
	}

	l.INFO(res);

	return 0;
}
