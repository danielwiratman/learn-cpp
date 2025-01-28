#include <iostream>
#include <logger.h>
#include <string>

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

bool
isSafe(vector<string> splits)
{
	if (stoi(splits[1]) > stoi(splits[0]))
	{
		for (int i = 1; i < splits.size(); i++)
		{
			if (stoi(splits[i]) <= stoi(splits[i - 1]))
			{
				return 0;
			}

			int diff = abs(stoi(splits[i]) - stoi(splits[i - 1]));
			if (diff > 3 || diff < 1)
			{
				return 0;
			}
		}
	}
	else
	{
		for (int i = 1; i < splits.size(); i++)
		{
			if (stoi(splits[i]) >= stoi(splits[i - 1]))
			{
				return 0;
			}

			int diff = abs(stoi(splits[i]) - stoi(splits[i - 1]));
			if (diff > 3 || diff < 1)
			{
				return 0;
			}
		}
	}

	return 1;
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

	int res = 0;

	string line;
	while (getline(in, line))
	{
		vector<string> splits = string_split(line, ' ');

		if (isSafe(splits))
		{
			l.DEBUG("Safe", splits);
			res++;
			goto continue_while_loop;
		}

		for (int i = 0; i < splits.size(); i++)
		{
			vector<string> newSplits = splits;

			newSplits.erase(newSplits.begin() + i);

			if (isSafe(newSplits))
			{
				l.DEBUG("Safe from", splits, "to", newSplits);
				res++;
				goto continue_while_loop;
			}
		}

		l.DEBUG("Unsafe", splits);

	continue_while_loop:
		continue;
	}

	l.DEBUG(res);
}
