#include "AVLTree.h"
#include "HashMap.h"
#include "OrderedMap.h"
#include <iostream>
#include <vector>

int main()
{
	OrderedMap<int> myMap;
	//test put and contains existing keys and values
	myMap.put(1, 2);
	std::cout << "(1, 2) added" << std::endl;
	std::cout << "contains key 1 = " << myMap.containsKey(1) << std::endl;
	std::cout << "contains value 2 = " << myMap.containsValue(2) << std::endl;
	myMap.put(3, 4);
	std::cout << "(3, 4) added" << std::endl;
	std::cout << "contains key 3 = " << myMap.containsKey(3) << std::endl;
	std::cout << "contains value 4 = " << myMap.containsValue(4) << std::endl;
	myMap.put(5, 6);
	std::cout << "(5, 6) added" << std::endl;
	std::cout << "contains key 5 = " << myMap.containsKey(5) << std::endl;
	std::cout << "contains value 6 = " << myMap.containsValue(6) << std::endl;
	myMap.put(7, 8);
	std::cout << "(7, 8) added" << std::endl;
	std::cout << "contains key 7 = " << myMap.containsKey(7) << std::endl;
	std::cout << "contains value 8 = " << myMap.containsValue(8) << std::endl;
	myMap.put(9, 10);
	std::cout << "(9, 10) added" << std::endl;
	std::cout << "contains key 9 = " << myMap.containsKey(9) << std::endl;
	std::cout << "contains value 10 = " << myMap.containsValue(10) << std::endl;
	//test adding a duplicate
	myMap.put(9, 10);
	std::cout << "(9, 10) added again" << std::endl;
	std::vector<int> keys = myMap.getKeys();
	std::cout << "count = " << keys.size() << std::endl;
	//test delete with an existing value
	myMap.remove(9);
	std::cout << "deleted key 9 = " << std::endl;
	std::cout << "contains key 9 = " << myMap.containsKey(9) << std::endl;
	std::cout << "contains value 10 = " << myMap.containsValue(10) << std::endl;
	//check size again after deleting
	keys = myMap.getKeys();
	std::cout << "count = " << keys.size() << std::endl;
	//test delete with a non-existent value
	myMap.remove(20);
	//check size again after deleting
	keys = myMap.getKeys();
	std::cout << "count = " << keys.size() << std::endl;
	//test contains with a non-existant value
	std::cout << "contains key 20 = " << myMap.containsKey(20) << std::endl;
	std::cout << "contains value 50 = " << myMap.containsValue(50) << std::endl;
	//test get
	std::cout << "value of key 7 = " << myMap.get(7) << std::endl;
	//check size again after getting
	keys = myMap.getKeys();
	std::cout << "count = " << keys.size() << std::endl;
	//test getKeys with filled OrderedMap
	keys = myMap.getKeys();
	std::cout << "keys: " << std::endl;
	for (int i : keys)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	//test if functions work when empty;
	myMap.clear();
	std::cout << "OrderedMap cleared" << std::endl;
	//test getKeys with empty OrderedMap
	keys = myMap.getKeys();
	std::cout << "keys: " << std::endl;
	for (int i : keys)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "OrderedMap is empty = " << myMap.isEmpty() << std::endl;
	std::cout << "count = " << keys.size() << std::endl;
	std::cout << "contains key 7 = " << myMap.containsKey(7) << std::endl;
	std::cout << "contains value 7 = " << myMap.containsValue(7) << std::endl;
	std::cout << "get 7 = " << myMap.get(7) << std::endl;
	std::cout << "remove 7 = " << myMap.remove(7) << std::endl;

	//end
	getchar();
}