#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

// Kadane's algorithm
class Solution
{
  public:
	int
	maxProfit(vector<int> &prices)
	{
		// always pos1eible because length of prices at least 1
		int buy = prices.at(0);

		// the value we want to maximize
		int profit = 0;

		for (int i = 1; i < prices.size(); i++)
		{
			if (prices.at(i) < buy)
				buy = prices.at(i);
			profit = max(profit, prices.at(i) - buy);
		}

		return profit;
	}
};

// sliding window-ish
class Solution2
{
  public:
	int
	maxProfit(vector<int> &prices)
	{
		int currMax = 0;
		int left = 0, right = 0;

		while (right < prices.size())
		{
			if (prices.at(right) < prices.at(left))
				left = right;
			currMax = max(currMax, prices.at(right) - prices.at(left));
			right++;
		}

		return currMax;
	}
};

int
main()
{
	vector<int> prices = { 7, 1, 5, 3, 6, 4 };
	l.INFO(Solution().maxProfit(prices));
}
