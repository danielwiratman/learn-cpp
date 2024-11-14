#include <vector>
#include <string>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	bool
	exist(vector<vector<char>> &board, string word)
	{
	}
};

int
main()
{
	vector<vector<char>> board = { { 'A', 'B', 'C', 'E' },
								   { 'S', 'F', 'C', 'S' },
								   { 'A', 'D', 'E', 'E' } };
	string word = "ABCCED";
	l.INFO(Solution().exist(board, word));
}
