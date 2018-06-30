#include <iostream>

#include "../include/Tree.h"
#include "../include/StringItem.h"
#include "../include/IntItem.h"
#include "../include/DoubleItem.h"
#include "../include/Record.h"

using namespace std;

int main() {
	Tree<int> tree;
	tree.add(1337);

	cout << tree.find(1337) << endl << endl;

	Record record;
	record.add(new StringItem(0, "Name", "Carl-Gustav"));
	record.add(new IntItem(1, "Age", 103));
	record.add(new DoubleItem(2, "Height", 1.52));

	Item* item1 = record.at(0);
	cout << item1->toString() << endl << endl;

	//Item* item2 = record.at(1);
	//cout << item2->toString() << endl << endl;

	cout << record.getSize() << endl;
	
	cout << "For loop:" << endl;
	for (int i = 0; i < record.getSize(); i++) {
		record.print(i);
	}
}
