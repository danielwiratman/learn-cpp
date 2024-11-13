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
		TrieNode *curr = root;

		for (char c : word)
		{
			if (c == '.')
			{
				for (TrieNode *t : curr->children)
				{
					dfs();
				}
			}
			else
			{
				if (curr->children[c - 'a'] == NULL)
					return false;
				curr = curr->children[c - 'a'];
			}
		}

		return true;
	}

	bool
	dfs()
	{
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
