#include <iostream>

#include "../include/Tree.h"
#include "../include/StringItem.h"
#include "../include/IntItem.h"
#include "../include/DoubleItem.h"
#include "../include/Record.h"
#include "../include/Table.h"
#include "../include/Database.h"
#include "../include/BinaryDB.h"

using namespace std;

void printStringArray (std::string* arr, int length);

int main() {
	Database* animals 	= new Database ("Animals");
	Database* planes 	= new Database ("Planes");
	Database* webshop	= new Database ("Webshop");
	Database* application	= new Database ("BinaryDB");

	BinaryDB binaryDB;
	binaryDB.createDatabase(animals);
	binaryDB.createDatabase(planes);
	binaryDB.createDatabase(webshop);
	binaryDB.createDatabase(application);

	// Print databases
	std::string* names = binaryDB.listAllDatabases();
	cout << "Databases: " << endl;
	printStringArray (names, binaryDB.getSize());
	delete[] names;
}

void printStringArray (std::string* arr, int length) {
	if (arr != NULL) {
		for (int i = 0; i < length; i++) {
			cout << arr[i] << endl;
		}
	}
}
