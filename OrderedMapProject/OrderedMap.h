#ifndef _ORDERED_MAP_
#define _ORDERED_MAP_
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
			vector<K> emptyVector(0);
			return emptyVector;
		}
	}
	bool isEmpty() {}
	void put(K key, V value) {}
	V remove(K key) {}
};

#endif