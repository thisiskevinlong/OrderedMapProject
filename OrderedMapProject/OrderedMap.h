#ifndef _ORDERED_MAP_
#define _ORDERED_MAP_
#include <algorithm>
#include <list>
#include <vector>

template <class K, class V>
class OrderedMap
{
private:
	std::list<K> keys;
public:
	void clear() {}
	bool containsKey(K key) {}
	bool containsValue(V value) {}
	V get(K key) {}
	std::vector<K> getKeys()
	{
		if (keys.empty())
		{
			std::vector<K> emptyVector;
			return emptyVector;
		}
		else
		{
			std::vector<K> keyVector(keys.size());
			std::copy(keys.begin(), keys.end(), keyVector.begin());
			return keyVector;
		}
	}
	bool isEmpty() {}
	void put(K key, V value) {}
	V remove(K key) {}
};

#endif