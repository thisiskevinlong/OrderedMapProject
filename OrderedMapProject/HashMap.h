#ifndef _HASH_MAP_
#define _HASH_MAP_
#include "AVLTree.h"

template <class K, class V>
class HashMap
{
private:
	AVLtree** trees;
	int capacity;
	int count;
public:
	HashMap* initializeHashMap()
	{
		HashMap* map = malloc(sizeof(HashMap));
		map->capacity = 100;
		map->count = 0;
		map->trees = malloc(sizeof(AVLtree*) * map->capacity);
		//for (int i = 0; i < map->capacity; i++)
		//	map->trees[i] = AVLtree();
		return map;
	}

	void clearHashMap(HashMap* map, std::list<K> keys)
	{
		//Removes all the 
		for (int i = 0; i < map->capacity; i++)
		{
			clear(map->trees[i]->root);
		}
		//Clears all the keys from the list
		keys.clear();
	}

	bool contains(K key)
	{

	}
	void insert(HashMap* map, char key[], double value);
	double get(HashMap* map, char key[]);
	bool delete(HashMap* map, char key[]);

};


#endif // !