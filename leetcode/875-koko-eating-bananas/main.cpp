#include <algorithm>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class Solution
{
  public:
	int
	minEatingSpeed(vector<int> &piles, int h)
	{
		int minSpeed = 1;
		int maxSpeed = *max_element(piles.begin(), piles.end());

		while (minSpeed <= maxSpeed)
		{
			int midSpeed = (minSpeed + maxSpeed) / 2;
			l.INFO("min mid max", minSpeed, midSpeed, maxSpeed);

			long currHour = 0;
			for (auto &bananas : piles)
				currHour += (bananas + midSpeed - 1) / midSpeed;

			// l.INFO("currHour", currHour);

			if (currHour <= h)
				maxSpeed = midSpeed - 1;
			else if (currHour >= h)
				minSpeed = midSpeed + 1;
		}

		return minSpeed;
	}
};

int
main()
{
	vector<int> piles = { 30 };
	int h = 20;

	l.INFO(Solution().minEatingSpeed(piles, h));
}
