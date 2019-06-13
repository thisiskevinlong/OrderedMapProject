#ifndef _HASH_MAP_
#define _HASH_MAP_
#include <stdexcept>
#include "AVLTree.h"

template <class V>
class HashMap
{
private:
	std::vector<AVLtree<V>*> trees;
	int capacity;
	int count;
public:

	/*
	 * Function: constructor
	 * Description: Initializes the map to an array of AVLtree objects.
	 * Output:
	 *     HashMap* - pointer to the newly created HashMap
	 */
	HashMap()
	{
		this->capacity = 10;
		this->count = 0;
		for (int i = 0; i < this->capacity; i++)
		{
			this->trees.push_back(new AVLtree<V>());
		}
		//trees = malloc(sizeof(AVLtree<V>*) * this->capacity);
	}

	/*
	 * Function: initializeHashMap
	 * Description: Initializes the map to an array of AVLtree objects.
	 * Output:
	 *     HashMap* - pointer to the newly created HashMap
	 */
	~HashMap()
	{
		//Removes all the nodes from each index
		for (int i = 0; i < this->capacity; i++)
		{
			AVLtree<V>* temp = this->trees.at(i);
			temp->clear(temp->root);
			//calls destructor of AVLtree
			delete (&(this->trees[i]));
		}
		delete(&trees);
	}

	/*
	 * Function: clearHashMap
	 * Description: Clears the HashMap by calling clear at each
	 *				vertex, keeping the AVLtree struct, but not 
	 *				any of its children.
	 * Input:
	 *     HashMap* - pointer to the HashMap
	 */
	void clearHashMap()
	{
		//Removes all the nodes from each index
		for (int i = 0; i < this->capacity; i++)
		{
			AVLtree<V>* temp = this->trees[i];
			temp->clear();
		}
		this->count = 0;
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
	bool contains(V value)
	{
		bool found = false;
		//Go from start and visit each TreeNode
		for (int i = 0; i < this->capacity && found; i++)
		{
			AVLtree<V>* temp = this->trees[i];
			if (temp->root != NULL)
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
	V get(unsigned long key)
	{
		double hash = hash(key, this->capacity);
		V* temp = search(this->trees[hash]);
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
	void insert(unsigned long key, V value, bool contains)
	{
		//if the hash map alredy has the value, delete it first
		if (contains)
		{
			AVLtree<V>* temp = this->trees.at(hash(key, this->capacity));
			temp->deleteKey(value);
		}
		this->trees.at(hash(key, this->capacity))->insertValue(value);
		this->count++;
	}

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
	double loadFactor()
	{
		int used = 0;
		for (int i = 0; i < this->capacity; i++)
		{
			if (this->trees[i]->root != NULL)
				used++;
		}
		return (double)used / this->capacity;
	}

	V remove(unsigned long key)
	{
		deleteKey(this->trees[hash(key)]);
	}
};

#endif // !