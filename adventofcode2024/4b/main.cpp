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
			if (matrix[i][j] == 'M')
			{
				// M in right bottom
				if (i > 1 && j > 1 &&
					((matrix[i - 1][j - 1] == 'A' &&
					  matrix[i - 2][j - 2] == 'S' && matrix[i - 2][j] == 'M' &&
					  matrix[i][j - 2] == 'S') ||
					 (matrix[i - 1][j - 1] == 'A' &&
					  matrix[i - 2][j - 2] == 'S' && matrix[i - 2][j] == 'S' &&
					  matrix[i][j - 2] == 'M')))
				{
					l.DEBUG("M in right bottom i", i, "j", j);
					res++;
				}

				// M in right top
				if (i < matrix.size() - 2 && j > 1 &&
					((matrix[i + 1][j - 1] == 'A' &&
					  matrix[i + 2][j - 2] == 'S' && matrix[i + 2][j] == 'M' &&
					  matrix[i][j - 2] == 'S') ||
					 (matrix[i + 1][j - 1] == 'A' &&
					  matrix[i + 2][j - 2] == 'S' && matrix[i + 2][j] == 'S' &&
					  matrix[i][j - 2] == 'M')))
				{
					l.DEBUG("M in right top i", i, "j", j);
					res++;
				}

				// M in left bottom
				if (i > 1 && j < matrix[0].size() - 2 &&
					((matrix[i - 1][j + 1] == 'A' &&
					  matrix[i - 2][j + 2] == 'S' && matrix[i - 2][j] == 'M' &&
					  matrix[i][j + 2] == 'S') ||
					 (matrix[i - 1][j + 1] == 'A' &&
					  matrix[i - 2][j + 2] == 'S' && matrix[i - 2][j] == 'S' &&
					  matrix[i][j + 2] == 'M')))
				{
					l.DEBUG("M in left bottom i", i, "j", j);
					res++;
				}

				// M in left top
				if (i < matrix.size() - 2 && j < matrix[0].size() - 2 &&
					((matrix[i + 1][j + 1] == 'A' &&
					  matrix[i + 2][j + 2] == 'S' && matrix[i + 2][j] == 'M' &&
					  matrix[i][j + 2] == 'S') ||
					 (matrix[i + 1][j + 1] == 'A' &&
					  matrix[i + 2][j + 2] == 'S' && matrix[i + 2][j] == 'S' &&
					  matrix[i][j + 2] == 'M')))
				{
					l.DEBUG("M in left top i", i, "j", j);
					res++;
				}
			}
		}
	}

	l.DEBUG(res / 2);
}
