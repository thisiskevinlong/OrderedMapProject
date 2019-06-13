#ifndef _HASH_MAP_
#define _HASH_MAP_
#include "AVLTree.h"

template <class K, class V>
class HashMap
{
private:
	Node** trees;
	int capacity;
	int count;
public:
	HashMap* initializeHashMap()
	{
		HashMap* map = malloc(sizeof(HashMap));
		map->capacity = 100;
		map->count = 0;
		map->trees = malloc(sizeof(Node*) * map->capacity);
		for (int i = 0; i < map->capacity; i++)
			map->trees[i] = NULL;
		return map;
	}
	void deleteHashMap()
	{
		Node* curr;
		Node* prev;
		for (int i = 0; i < map->capacity; i++)
		{
			if (map->nodes[i] != NULL)
			{
				delete(map->trees[i]);
			}
		}
		free(map);
	}
	bool contains(K key)
	{

	}
	void insert(HashMap* map, char key[], double value);
	double get(HashMap* map, char key[]);
	bool delete(HashMap* map, char key[]);

};


#endif // !
