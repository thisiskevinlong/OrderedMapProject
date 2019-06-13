#ifndef _HASH_MAP_
#define _HASH_MAP_
#include "AVLTree.h"

template <class K, class V>
class HashMap
{
private:
	AVLTree** trees;
	int capacity;
	int count;
public:
	HashMap* initializeHashMap();
	void deleteHashMap();
	bool contains(K);
	void insert(HashMap* map, char key[], double value);
	double get(HashMap* map, char key[]);
	bool delete(HashMap* map, char key[]);
};


#endif // !