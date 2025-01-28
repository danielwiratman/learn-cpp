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

#define TOLERATE_THRESHOLD 1

int
main()
{
	ifstream in("input.txt");
	if (!in)
	{
		l.ERROR("Could not open input.txt");
		return 1;
	}

	int res = 0;

	string line;
	while (getline(in, line))
	{
		vector<string> splits = string_split(line, ' ');

		int inc = 1;
		int tolerate = 0;

		if (stoi(splits[1]) > stoi(splits[0]))
		{
			// increase
			for (int i = 1; i < splits.size(); i++)
			{
				if (stoi(splits[i]) <= stoi(splits[i - 1]))
				{
					tolerate++;
					if (tolerate > TOLERATE_THRESHOLD)
						inc = 0;
					continue;
				}

				int diff = abs(stoi(splits[i]) - stoi(splits[i - 1]));
				if (diff > 3 || diff < 1)
				{
					tolerate++;
					if (tolerate > TOLERATE_THRESHOLD)
						inc = 0;
					continue;
				}
			}
		}
		else
		{
			// decrease
			for (int i = 1; i < splits.size(); i++)
			{
				if (stoi(splits[i]) >= stoi(splits[i - 1]))
				{
					tolerate++;
					if (tolerate > TOLERATE_THRESHOLD)
						inc = 0;
					continue;
				}

				int diff = abs(stoi(splits[i]) - stoi(splits[i - 1]));
				if (diff > 3 || diff < 1)
				{
					tolerate++;
					if (tolerate > TOLERATE_THRESHOLD)
						inc = 0;
					continue;
				}
			}
		}

		if (inc == 0)
			l.INFO("Invalid ", splits);
		else
			l.INFO("Valid  ", splits);

		res += inc;
	}

	l.INFO(res);
}
