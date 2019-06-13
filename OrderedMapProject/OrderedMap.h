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
	HashMap map;
	std::list<K> keys;
public:

	/*
	 * Function: clear
	 * Description: Deletes all elements in the map and all 
	 *				keys in the linked list
	 */
	void clear() 
	{
		//call to get rid of all the nodes
		map.clearHashMap();
		//call to remove all keys in insertion order
		keys.clear();
	}

	/*
	 * Function: containsKey
	 * Description: Reports if the key exists or not
	 * Input:
	 *     key - the unsigned long key
	 * Output:
	 *    bool - 0 if does not exist, 1 if exists
	 */
	bool containsKey(unsigned long key)
	{
		//looks through the keys for the unsigned int
		return (find(keys.begin(), keys.end(), key) != keys.end());
	}

	/*
	 * Function: containsValue
	 * Description: searches the map for the given value 
	 *				and reports if it exists
	 * Input:
	 *     value - the value to search for
	 * Output:
	 *    bool - 0 if does not contains, 1 if exists
	 */
	bool containsValue(V value) 
	{
		
	}

	/*
	 * Function: get
	 * Description: returns the value at the given key – 
	 *				throws an exception if the key does not exist
	 * Input:
	 *     key - the unsigned long key
	 * Output:
	 *    V - the value of the key
	 */
	V get(unsigned long key) 
	{
		try
		{

		}
		catch ()
		{

		}
	}

	/*
	 * Function: getKeys
	 * Description: returns a vector of all of the keys in insertion 
	 *				order – if there are no keys it returns an empty vector
	 * Output:
	 *    vector<unsigned long> - the keys
	 */
	std::vector<unsigned long> getKeys()
	{
		if (keys.empty())
		{
			std::vector<unsigned long> emptyVector;
			return emptyVector;
		}
		else
		{
			std::vector<unsigned long> keyVector(keys.size());
			std::copy(keys.begin(), keys.end(), keyVector.begin());
			return keyVector;
		}
	}

	/*
	 * Function: getKeys
	 * Description: reports if the map is empty or not
	 * Output:
	 *    bool - if the structure is empty or not
	 */
	bool isEmpty()
	{
		return keys.empty();
	}

	/*
	 * Function: put
	 * Description: adds the key-value pair to the map and the key to the list,
	 *				or replaces the existing value at that key in the map if it
	 *				already exists (There is no need to reorder the key to the
	 *				end of the list if this is a replacement.)
	 * Input:
	 *     key - the unsigned long key
	 *     value - the value corresponding to the key
	 */
	void put(unsigned long key, V value) 
	{
		
	}

	/*
	 * Function: remove
	 * Description: removes the key-value pair from the map and the key from
	 *				the linked list – throws an exception if the key does not 
	 *				exists.
	 * Input:
	 *     key - the unsigned long key
	 * Output:
	 *    V - the value of the key
	 */
	V remove(K key) 
	{
		
	}
};

#endif