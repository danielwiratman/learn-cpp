#include <logger.h>
#include <vector>

using namespace std;

Logger &l = Logger::get();

class Solution
{
  public:
	void
	merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
	{
		int i = m + n - 1;
		int j = m - 1;
		int k = n - 1;

		while (k > -1)
		{
			if (j > -1 && nums1[j] > nums2[k])
			{
				nums1[i] = nums1[j];
				i--;
				j--;
			}
			else
			{
				nums1[i] = nums2[k];
				i--;
				k--;
			}
		}
	}
};

int
main()
{
	vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
	int m = 3;
	vector<int> nums2 = { 2, 5, 6 };
	int n = 3;
	Solution().merge(nums1, m, nums2, n);

	l.INFO(nums1);
}
