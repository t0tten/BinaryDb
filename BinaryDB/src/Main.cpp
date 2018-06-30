#include <iostream>

#include "../include/Tree.h"

using namespace std;

int main() {
	Tree<int> tree;
	tree.add(1337);

	cout << tree.find(1337) << endl;
}
