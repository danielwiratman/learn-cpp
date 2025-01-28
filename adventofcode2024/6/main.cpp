#include <fstream>
#include <vector>
#include "logger.h"

using namespace std;

Logger &l = Logger::get();

int
main()
{
	ifstream file("input2.txt");

	vector<vector<char>> chars;

	int facing = 2; // ltrb

	string line;
	while (getline(file, line))
		chars.push_back(vector<char>(line.begin(), line.end()));

	int startI = 0, startJ = 0;

	for (int i = 0; i < chars.size(); i++)
	{
		for (int j = 0; j < chars[0].size(); j++)
		{
			if (chars[i][j] == '^')
			{
				startI = i;
				startJ = j;
				goto break_outer_loop;
			}
		}
	}

break_outer_loop:
	int caretI = startI, caretJ = startJ;

facing_switch:
	switch (facing)
	{
		case 1:
			while (chars[caretI][caretJ - 1] != '#')
			{
				caretJ--;

				if (caretI > startI && caretJ == startJ)
					l.DEBUG(caretI, caretJ);

				chars[caretI][caretJ] = 'X';
				if (caretJ < 1)
					goto count_X;
			}

			facing = 2;

			goto facing_switch;
		case 2:
			while (chars[caretI - 1][caretJ] != '#')
			{
				caretI--;

				if (caretI == startI && caretJ < startJ)
					l.DEBUG(caretI, caretJ);

				chars[caretI][caretJ] = 'X';
				if (caretI < 1)
					goto count_X;
			}

			facing = 3;

			goto facing_switch;
		case 3:
			while (chars[caretI][caretJ + 1] != '#')
			{
				caretJ++;

				if (caretI < startI && caretJ == startJ)
					l.DEBUG(caretI, caretJ);

				chars[caretI][caretJ] = 'X';
				if (caretJ > chars[0].size() - 2)
					goto count_X;
			}
			facing = 4;
			goto facing_switch;
		case 4:
			while (chars[caretI + 1][caretJ] != '#')
			{
				caretI++;

				if (caretI == startI && caretJ > startJ)
					l.DEBUG(caretI, caretJ);

				chars[caretI][caretJ] = 'X';
				if (caretI > chars.size() - 2)
					goto count_X;
			}
			facing = 1;

			goto facing_switch;
	}

count_X:
	int res = 0;

	for (auto &line : chars)
		l.DEBUG(line);

	for (int i = 0; i < chars.size(); i++)
	{
		for (int j = 0; j < chars[0].size(); j++)
		{
			if (chars[i][j] == 'X')
				res++;
		}
	}

	l.DEBUG(res);
}
