#include <iostream>
#include "OrderedMap.h"

using namespace std;

int main()
{
	cout << "Entered main finally!" << endl;
	OrderedMap<string> map;
	map.put(1, "Hello");
	
	//end
	getchar();
}