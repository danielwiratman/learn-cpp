#include <string>
#include <unordered_set>

using namespace std;

class TrieWrong
{
	unordered_set<string> hSet;

  public:
	TrieWrong() {}

	void
	insert(string word)
	{
		hSet.insert(word);
	}

	bool
	search(string word)
	{
		return hSet.find(word) != hSet.end();
	}

	bool
	startsWith(string prefix)
	{
		if (hSet.empty())
			return false;

		for (string s : hSet)
		{
			if (s.size() < prefix.size())
				continue;

			bool stringInvalid = false;
			for (int i = 0; i < prefix.size(); i++)
			{
				if (s[i] != prefix[i])
				{
					stringInvalid = true;
					break;
				}
			}

			if (stringInvalid)
				continue;

			return true;
		}
		return false;
	}
};
