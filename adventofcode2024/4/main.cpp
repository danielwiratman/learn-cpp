#include <fstream>
#include <vector>
#include "logger.h"

using namespace std;

Logger &l = Logger::get();

int
main()
{
	ifstream file("input.txt");
	vector<vector<char>> matrix;

	int res = 0;

	string line;
	while (getline(file, line))
		matrix.push_back(vector<char>(line.begin(), line.end()));

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == 'X')
			{
				if (j > 2 && matrix[i][j - 3] == 'S' &&
					matrix[i][j - 2] == 'A' && matrix[i][j - 1] == 'M')
				{
					l.DEBUG("Found horizontal backward, i", i, "j", j);
					res++;
				}

				if (j < matrix[0].size() - 3 && matrix[i][j + 3] == 'S' &&
					matrix[i][j + 2] == 'A' && matrix[i][j + 1] == 'M')
				{
					l.DEBUG("Found horizontal forward, i", i, "j", j);
					res++;
				}

				if (i > 2 && matrix[i - 3][j] == 'S' &&
					matrix[i - 2][j] == 'A' && matrix[i - 1][j] == 'M')
				{
					l.DEBUG("Found vertical up, i", i, "j", j);
					res++;
				}

				if (i < matrix.size() - 3 && matrix[i + 3][j] == 'S' &&
					matrix[i + 2][j] == 'A' && matrix[i + 1][j] == 'M')
				{
					l.DEBUG("Found vertical down, i", i, "j", j);
					res++;
				}

				if (i > 2 && j > 2 && matrix[i - 3][j - 3] == 'S' &&
					matrix[i - 2][j - 2] == 'A' && matrix[i - 1][j - 1] == 'M')
				{
					l.DEBUG("Found diagonal up left, i", i, "j", j);
					res++;
				}

				if (i < matrix.size() - 3 && j < matrix.size() - 3 &&
					matrix[i + 3][j + 3] == 'S' &&
					matrix[i + 2][j + 2] == 'A' && matrix[i + 1][j + 1] == 'M')
				{
					l.DEBUG("Found diagonal down right, i", i, "j", j);
					res++;
				}

				if (i > 2 && j < matrix.size() - 3 &&
					matrix[i - 3][j + 3] == 'S' &&
					matrix[i - 2][j + 2] == 'A' && matrix[i - 1][j + 1] == 'M')
				{
					l.DEBUG("Found diagonal up right, i", i, "j", j);
					res++;
				}

				if (i < matrix.size() - 3 && j > 2 &&
					matrix[i + 3][j - 3] == 'S' &&
					matrix[i + 2][j - 2] == 'A' && matrix[i + 1][j - 1] == 'M')
				{
					l.DEBUG("Found diagonal down left, i", i, "j", j);
					res++;
				}
			}
		}
	}

	l.DEBUG(res);
}
