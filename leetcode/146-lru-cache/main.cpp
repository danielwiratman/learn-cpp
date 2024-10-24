#include <algorithm>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>
#include <string>
#include <logger.h>

using namespace std;

auto &l = Logger::get();

class LRUCache
{
	unordered_map<int, list<pair<int, int>>::iterator> data;
	list<pair<int, int>> cachedKeys;

  public:
	LRUCache(int capacity) { cachedKeys = list<pair<int, int>>(capacity); }

	int
	get(int key)
	{
		if (data.find(key) != data.end())
		{
			auto it = data.at(key);
			cachedKeys.push_back({ it->first, it->second });
			cachedKeys.erase(it);
			data[key] = --cachedKeys.end();
			return data.at(key)->second;
		}
		return -1;
	}

	void
	put(int key, int value)
	{
		if (data.find(key) != data.end())
		{
			cachedKeys.push_back({ key, value });
			cachedKeys.erase(data.at(key));
			data.at(key) = --cachedKeys.end();
			return;
		}
		int evictedKey = cachedKeys.front().first;
		data.erase(evictedKey);
		cachedKeys.pop_front();

		cachedKeys.push_back({ key, value });
		data[key] = --cachedKeys.end();
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
