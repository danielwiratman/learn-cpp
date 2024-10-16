#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
  public:
	bool
	areSentencesSimilar(string sentence1, string sentence2)
	{
		vector<string> words1 = splitToWords(sentence1);
		vector<string> words2 = splitToWords(sentence2);

		int i = 0, j = 0;
		int n1 = words1.size(), n2 = words2.size();

		while (i < n1 && i < n2 && words1[i] == words2[i])
		{
			i++;
		}

		while (j < n1 - i && j < n2 - i &&
			   words1[n1 - j - 1] == words2[n2 - j - 1])
		{
			j++;
		}

		return i + j == min(n1, n2);
	}

	vector<string>
	splitToWords(string sentence)
	{
		vector<string> result;
		stringstream ss(sentence);
		string word;

		while (getline(ss, word, ' '))
		{
			result.push_back(word);
		}

		return result;
	}
};

int
main()
{
	string sentence1 = "of", sentence2 = "A lot of words";
	printf("%b", Solution().areSentencesSimilar(sentence1, sentence2));
}
