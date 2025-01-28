#include <fstream>
#include <iostream>
#include <logger.h>
#include <sstream>
#include <string>

Logger &l = Logger::get();

using namespace std;

bool
isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool
isNumber(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (!isDigit(s[i]))
			return false;
	}
	return true;
}

int
main()
{
	string fileString;
	ifstream file("input.txt");

	int res = 0;

	char ch;

	while (file >> ch)
		fileString += ch;

	int i = 0;
	int j = 4;

	int enabled = true;

	while (j < fileString.size())
	{
		if (fileString.substr(i, j - i) == "do()")
		{
			enabled = true;
			j++;
			i = j - 4;
			continue;
		}

		if (fileString.substr(i, 7) == "don't()")
		{
			enabled = false;
			j++;
			i = j - 4;
			continue;
		}

		if (fileString.substr(i, j - i) == "mul(")
		{
			i += 4;
			j = i;
			string numAStr = "";

			while (isDigit(fileString[j]))
			{
				numAStr += fileString[j];
				j++;
			}
			if (numAStr.size() == 0 || !isNumber(numAStr))
			{
				j++;
				i = j - 4;
				continue;
			}
			int numA = stoi(numAStr);

			if (fileString[j] != ',')
			{
				j++;
				i = j - 4;
				continue;
			}

			j++;
			i = j;

			string numBStr = "";
			while (isDigit(fileString[j]))
			{
				numBStr += fileString[j];
				j++;
			}
			if (numBStr.size() == 0 || !isNumber(numBStr))
			{
				j++;
				i = j - 4;
				continue;
			}
			int numB = stoi(numBStr);

			if (fileString[j] != ')')
			{
				j++;
				i = j - 4;
				continue;
			}

			l.DEBUG(numA, numB);

			if (enabled)
				res += numA * numB;

			j++;
			i = j - 4;
		}

		i++;
		j++;
	}

	l.DEBUG(res);
}
