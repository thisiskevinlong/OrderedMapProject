#ifndef _ORDERED_MAP_
#define _ORDERED_MAP_
#include <algorithm>
#include <list>
#include <vector>
#include "HashMap.h"

template <class V>
class OrderedMap
{
private:
	HashMap hashMap;
	std::list<int> keys;
public:
	void clear()
	{
		hashMap.clearHashMap();
		keys.clear();
	}

	bool containsKey(int key)
	{
		return (find(keys.begin(), keys.end()) != keys.end());
	}

	bool containsValue(V value) {}


	V get(int key) {}

	std::vector<int> getKeys()
	{
		if (keys.empty())
		{
			std::vector<int> emptyVector;
			return emptyVector;
		}
		else
		{
			std::vector<int> keyVector(keys.size());
			std::copy(keys.begin(), keys.end(), keyVector.begin());
			return keyVector;
		}
	}

	bool isEmpty()
	{
		return (keys.empty());
	}

	void put(int key, V value) {}
	V remove(int key) {}
};

#endif