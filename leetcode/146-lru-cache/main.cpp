#include <unordered_map>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class LRUCache
{
	unordered_map<int, int> data;
	vector<int> cachedKeys;

  public:
	LRUCache(int capacity) { cachedKeys = vector<int>(capacity, 0); }

	int
	get(int key)
	{
		if (data.find(key) != data.end())
		{
			for (int i = 1; i < cachedKeys.size(); i++)
				cachedKeys[i - 1] = cachedKeys[i];
			cachedKeys[cachedKeys.size() - 1] = key;
			return data[key];
		}
		return -1;
	}

	void
	put(int key, int value)
	{
		data[key] = value;

		for (int i = 0; i < cachedKeys.size(); i++)
		{
			if (cachedKeys[i] == key)
			{
				data[key] = value;
				for (int i = 1; i < cachedKeys.size(); i++)
					cachedKeys[i - 1] = cachedKeys[i];
				cachedKeys[cachedKeys.size() - 1] = key;
				return;
			}
		}
		int evictedKey = cachedKeys[0];
		data.erase(evictedKey);

		for (int i = 1; i < cachedKeys.size(); i++)
			cachedKeys[i - 1] = cachedKeys[i];
		cachedKeys[cachedKeys.size() - 1] = key;
	}
};

int
main()
{
	LRUCache *obj = new LRUCache(2);
	obj->put(2, 1);
	obj->put(1, 1);
	obj->put(2, 3);
	obj->put(4, 1);
	l.INFO(obj->get(1));
	l.INFO(obj->get(2));
}
