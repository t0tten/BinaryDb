#include <iostream>

#include "../include/Tree.h"
#include "../include/StringItem.h"
#include "../include/IntItem.h"
#include "../include/DoubleItem.h"

using namespace std;

int main() {
	Tree<int> tree;
	tree.add(1337);

	cout << tree.find(1337) << endl;

	Item** items = new Item*[4];

	for(int i = 0; i < 4; i++) {
		items[i] = NULL;
	}

	items[0] = new StringItem(0, "name", "rasmus");
	items[1] = new IntItem(1, "Age", 30);
	items[2] = new DoubleItem(2, "Length", 1.74);

	cout << endl;
	for(int i = 0; i < 4; i++) {
		if(items[i] != NULL) {
			cout << items[i]->toString() << endl << endl;
		}
	}

}
