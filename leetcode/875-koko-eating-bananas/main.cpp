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

			int currHour = 0;
			for (auto &bananas : piles)
				currHour += (bananas + midSpeed - 1) / midSpeed;

			// time took too short, need to slow down speed to make time longer
			if (currHour <= h)
				maxSpeed = midSpeed - 1;
			// time took too long, need to speed up speed to make time shorter
			else if (currHour > h)
				minSpeed = midSpeed + 1;
		}

		return -1;
	}
};

int
main()
{
	vector<int> piles = { 30, 11, 23, 4, 20 };
	int h = 5;

	l.INFO(Solution().minEatingSpeed(piles, h));
}
