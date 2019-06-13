#ifndef _HASH_MAP_
#define _HASH_MAP_
#include <stdexcept>
#include "AVLTree.h"

template <class V>
class HashMap
{
private:
	AVLtree** trees;
	int capacity;
	int count;
public:

	/*
	 * Function: initializeHashMap
	 * Description: Initializes the map to an array of AVLtree objects.
	 * Output:
	 *     HashMap* - pointer to the newly created HashMap
	 */
	HashMap* initializeHashMap()
	{
		HashMap* map = malloc(sizeof(HashMap));
		map->capacity = 10;
		map->count = 0;
		map->trees = malloc(sizeof(AVLtree*) * map->capacity);
		return map;
	}

	/*
	 * Function: clearHashMap
	 * Description: Clears the HashMap by calling clear at each
	 *				vertex, keeping the AVLtree struct, but not 
	 *				any of its children.
	 * Input:
	 *     HashMap* - pointer to the HashMap
	 */
	void clearHashMap(HashMap* map)
	{
		//Removes all the nodes from each index
		for (int i = 0; i < map->capacity; i++)
		{
			clear(map->trees[i]->root);
		}
		map->count = 0;
	}

	/*
	 * Function: containsValue
	 * Description: searches the map for the given value
	 *				and reports if it exists
	 * Input:
	 *     map   - hash map pointer
	 *     value - the value to search for
	 * Output:
	 *    bool - 0 if does not contains, 1 if exists
	 */
	bool contains(HashMap* map, V value)
	{
		bool found = false;
		//Go from start and visit each TreeNode
		for (int i = 0; i < map->capacity && found; i++)
		{
			if (search(map->capacity[i]) != NULL)
				found = true;
		}
		return found;
	}


	/*
	 * Function: get
	 * Description: returns the value with the given key
	 * Input:
	 *     map - hash map pointer
	 *     key - the unsigned long key
	 * Output:
	 *    V - the value of the key
	 */
	V get(HashMap* map, unsigned long key)
	{
		double hash = hash(key, map->capacity);
		V* temp = search(map->trees[hash]);
		if (temp == NULL)
			throw std::invalid_argument("No such value");
		return temp;
	}

	/*
	 * Function: containsValue
	 * Description: searches the map for the given value
	 *				and reports if it exists
	 * Input:
	 *     map   - hash map pointer
	 *     value - the value to search for
	 * Output:
	 *    bool - 0 if does not contains, 1 if exists
	 */
	void insert(HashMap* map, int key, V value, bool contains)
	{
		if (contains)
			deleteKey(map->trees[hash(key)]);
		map->trees[hash(key)]->insertValue(value);
	}

	bool delete(HashMap* map, char key[]);


	/*
	 * Function: hash
	 * Description: hashes the key by doing some complicated math.
	 * Input:
	 *     key - the unsigned long key
	 */
	unsigned int hash(unsigned long key, int capacity) {
		key = (~key) + (key << 18); // key = (key << 18) - key - 1;
		key = key ^ (key >> 31);
		key = key * 21; // key = (key + (key << 2)) + (key << 4);
		key = key ^ (key >> 11);
		key = key + (key << 6);
		key = key ^ (key >> 22);
		return (unsigned int)key % capacity;
	}

	/*
	 * Function: loadFactor
	 * Description: calculates the loadFactor of the hashMap.
	 * Input:
	 *     map - the map
	 * Output:
	 *	   double - the amount out of 1 that the map is filled
	 */
	double loadFactor(HashMap* map)
	{
		int used = 0;
		for (int i = 0; i < map->capacity; i++)
		{
			if (map->trees[i]->root != NULL)
				used++;
		}
		return (double)used / map->capacity;
	}
};


#endif // !