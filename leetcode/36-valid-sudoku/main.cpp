#include <unordered_set>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	bool
	isValidSudoku(vector<vector<char>> &board)
	{
		vector<unordered_set<char>> rows(9), cols(9), boxes(9);

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
					continue;

				int boxIdx = i / 3 * 3 + j / 3;

				if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) ||
					boxes[boxIdx].count(board[i][j]))
					return false;

				rows[i].insert(board[i][j]);
				cols[j].insert(board[i][j]);
				boxes[boxIdx].insert(board[i][j]);
			}
		}
		return true;
	}
};

int
main()
{
	vector<vector<char>> board = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
	};

	l.INFO(Solution().isValidSudoku(board));
}
