#include <iostream>

#include "../include/Tree.h"
#include "../include/StringItem.h"
#include "../include/IntItem.h"
#include "../include/DoubleItem.h"
#include "../include/Record.h"
#include "../include/Table.h"

using namespace std;

int main() {
	Tree<int> tree;
	tree.add(1337);

	cout << tree.find(1337) << endl << endl;

	Table* table = new Table ("Animals");
	cout << table->getTableName() << endl;
}
