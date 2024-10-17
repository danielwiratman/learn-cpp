#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class Solution
{
  public:
	int
	maximumSwap(int num)
	{
		// get the most right occurence of each digit
		vector<int> mostRightIdxOfDigit(10, -1);

		string numStr = to_string(num);
		for (int i = 0; i < numStr.size(); i++)
		{
			mostRightIdxOfDigit[ctoi(numStr[i])] = i;
		}

		for (int i = 0; i < numStr.size(); i++)
		{
			for (int j = 9; j > ctoi(numStr[i]); j--)
			{
				if (mostRightIdxOfDigit[j] > i)
				{
					swap(numStr[i], numStr[mostRightIdxOfDigit[j]]);
					return stoi(numStr);
				}
			}
		}

		return num;
	}

	int
	ctoi(char c)
	{
		return c - '0';
	}
};

int
main()
{
	int num = 115;
	printf("%d\n", Solution().maximumSwap(num));
}
