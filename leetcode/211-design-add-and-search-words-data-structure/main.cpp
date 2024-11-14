#include <vector>
#include <string>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

class TrieNode
{
  public:
	vector<TrieNode *> children;
	int wordCount;

	TrieNode() : children(26, nullptr), wordCount(0) {}
};

class WordDictionary
{
	TrieNode *root;

  public:
	WordDictionary() { root = new TrieNode(); }

	void
	addWord(string word)
	{
		TrieNode *curr = root;

		for (char c : word)
		{
			if (curr->children[c - 'a'] == NULL)
				curr->children[c - 'a'] = new TrieNode();

			curr = curr->children[c - 'a'];
		}
		curr->wordCount++;
	}

	bool
	search(string word)
	{
		return dfs(word, 0, root);
	}

	bool
	dfs(string word, int wordIdx, TrieNode *root)
	{
		TrieNode *curr = root;

		for (int i = wordIdx; i < word.size(); i++)
		{
			char c = word[i];
			if (c == '.')
			{
				for (TrieNode *child : curr->children)
				{
					if (child && dfs(word, i + 1, child))
						return true;
				}
				return false;
			}
			else
			{
				if (curr->children[c - 'a'] == NULL)
					return false;

				curr = curr->children[c - 'a'];
			}
		}

		return curr->wordCount;
	}
};

int
main()
{
	WordDictionary *wordDictionary = new WordDictionary();
	wordDictionary->addWord("bad");
	wordDictionary->addWord("dad");
	wordDictionary->addWord("mad");
	l.INFO(wordDictionary->search("pad")); // return False
	l.INFO(wordDictionary->search("bad")); // return True
	l.INFO(wordDictionary->search(".ad")); // return True
	l.INFO(wordDictionary->search("b..")); // return True
}
