#include <unordered_set>
#include <vector>
#include <string>
#include <logger.h>
#include <dwlc.h>

using namespace std;

auto &l = Logger::get();

struct TrieNode
{
	vector<TrieNode *> children;
	int wordCount;

	TrieNode() : children(26, nullptr), wordCount(0) {}
};

class Trie
{
  private:
	TrieNode *root;

  public:
	Trie() { root = new TrieNode(); }

	void
	insert(string word)
	{
		TrieNode *curr = root;

		for (char c : word)
		{
			if (curr->children[c - 'a'] == NULL)
			{
				TrieNode *newNode = new TrieNode();
				curr->children[c - 'a'] = newNode;
			}

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
			if (curr->children[c - 'a'] == NULL)
				return false;
			curr = curr->children[c - 'a'];
		}

		return curr->wordCount > 0;
	}

	bool
	startsWith(string prefix)
	{
		TrieNode *curr = root;

		for (char c : prefix)
		{
			if (curr->children[c - 'a'] == NULL)
				return false;
			curr = curr->children[c - 'a'];
		}

		return true;
	}
};

int
main()
{
	Trie *trie = new Trie();
	trie->insert("hotdog");
	l.INFO(trie->startsWith("dog"));
}
