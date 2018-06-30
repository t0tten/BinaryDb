#include <iostream>
#include "../include/Tree.h"
#include <assert.h>

using namespace std;

void testAddOne() {
	Tree<int> tree;
	tree.add(10);

	assert(tree.size() == 1);
}

void testIsEmptyAndClear() {
	Tree<int> tree;
	assert(tree.isEmpty() == true);

	tree.add(10);
	assert(tree.isEmpty() == false);

	tree.clear();
	assert(tree.isEmpty() == true);
	assert(tree.size() == 0);
}

void testGetLowestValueAndGetHighestValueAndGetSize () {
	Tree<int> tree;
	tree.add(10);
	tree.add(15);
	tree.add(11);
	tree.add(29);
	tree.add(4);
	tree.add(5);
	tree.add(6);
	tree.add(1);
	tree.add(300);
	tree.add(25);

	assert(tree.size() == 10);
	assert(tree.getMin() == 1);
	assert(tree.getMax() == 300);
}

void testFindARealValue() {
	Tree<int> tree;
	tree.add(10);
	tree.add(15);
	
	assert(tree.find(15) == 15);
}

void testFindAFictionValue() {
	Tree<int> tree;
	tree.add(10);
	tree.add(15);
	
	try {
		tree.find(16);
	} catch (char const* e) {
		assert(e == "No match found.");
	}
}

void testRemoveNodeWhenChildrenAreNull() {
	Tree<int> tree;
	tree.add(10);
	tree.add(11);
	tree.add(15);
	
	assert(tree.remove(16) == false);
	assert(tree.remove(15) == true);

	try {
		assert(tree.find(15) != 15);
	} catch (char const* e) {
		assert(e = "No match found.");
	}

	try {
		assert(tree.find(10) == 10);
		assert(tree.find(11) == 11);
	} catch (char const* e) {
		cout << e << endl;
	}
}

void testRemoveNodeWhenLeftIsNull() {
	Tree<int> tree;
	tree.add(10);
	tree.add(11);
	tree.add(15);
	
	assert(tree.remove(11) == true);

	try {
		assert(tree.find(11) != 11);
	} catch (char const* e) {
		assert(e = "No match found.");
	}

	try {
		assert(tree.find(10) == 10);
		assert(tree.find(15) == 15);
	} catch (char const* e) {
		cout << e << endl;
	}
}

void testRemoveNodeWhenRightIsNull() {
	Tree<int> tree;
	tree.add(10);
	tree.add(8);
	tree.add(4);
	
	assert(tree.remove(8) == true);

	try {
		assert(tree.find(8) != 8);
	} catch (char const* e) {
		assert(e = "No match found.");
	}

	try {
		assert(tree.find(10) == 10);
		assert(tree.find(4) == 4);
	} catch (char const* e) {
		cout << e << endl;
	}
}

void testRemoveNodeWhenNoneIsNull() {
	Tree<int> tree;
	tree.add(10);
	tree.add(15);
	tree.add(12);
	tree.add(29);
	tree.add(300);
	tree.add(20);
	
	assert(tree.remove(15) == true);

	try {
		assert(tree.find(15) != 15);
	} catch (char const* e) {
		assert(e = "No match found.");
	}

	try {
		assert(tree.find(12) == 12);
		assert(tree.find(300) == 300);
		assert(tree.find(20) == 20);
	} catch (char const* e) {
		cout << e << endl;
	}
}

void testRootRemoveNodeWhenChildrenAreNull() {
	Tree<int> tree;
	tree.add(10);
	
	assert(tree.remove(10) == true);

	try {
		assert(tree.find(10) != 10);
	} catch (char const* e) {
		assert(e = "No match found.");
	}

	assert(tree.size() == 0);
	assert(tree.isEmpty() == true);
}

void testRootRemoveNodeWhenLeftIsNull() {
	Tree<int> tree;
	tree.add(10);
	tree.add(15);
	
	assert(tree.remove(10) == true);

	try {
		assert(tree.find(10) != 10);
	} catch (char const* e) {
		assert(e = "No match found.");
	}

	try {
		assert(tree.find(15) == 15);
		assert(tree.size() == 1);
	} catch (char const* e) {
		cout << e << endl;
	}
}

void testRootRemoveNodeWhenRightIsNull() {
	Tree<int> tree;
	tree.add(10);
	tree.add(8);
	
	assert(tree.remove(10) == true);

	try {
		assert(tree.find(10) != 10);
	} catch (char const* e) {
		assert(e = "No match found.");
	}

	try {
		assert(tree.find(8) == 8);
		assert(tree.size() == 1);
	} catch (char const* e) {
		cout << e << endl;
	}
}

void testRootRemoveNodeWhenNoneIsNull() {
	Tree<int> tree;
	tree.add(10);
	tree.add(15);
	tree.add(5);
	tree.add(7);
	
	assert(tree.remove(10) == true);

	try {
		assert(tree.find(10) != 10);
	} catch (char const* e) {
		assert(e = "No match found.");
	}

	try {
		assert(tree.find(15) == 15);
		assert(tree.find(5) == 5);
		assert(tree.find(7) == 7);
		assert(tree.size() == 3); 
	} catch (char const* e) {
		cout << e << endl;
	}
}

int main() {

	// Misc
	testAddOne();
	testIsEmptyAndClear();
	testGetLowestValueAndGetHighestValueAndGetSize();

	// Find
	testFindARealValue();
	testFindAFictionValue();

	// Remove tests - non-root
	testRemoveNodeWhenChildrenAreNull();
	testRemoveNodeWhenLeftIsNull();
	testRemoveNodeWhenRightIsNull();
	testRemoveNodeWhenNoneIsNull();

	// Remove tests - root
	testRootRemoveNodeWhenChildrenAreNull();
	testRootRemoveNodeWhenLeftIsNull();
	testRootRemoveNodeWhenRightIsNull();
	testRootRemoveNodeWhenNoneIsNull();
}


