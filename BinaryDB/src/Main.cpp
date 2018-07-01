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
bool addRecordToTable (Database*& database, std::string tableName, Record* record);

int main() {
	Item* id 		= new IntItem(0, "id", 0);
	Item* username 		= new StringItem(1, "username", "MrBig");
	Item* firstname 	= new StringItem(2, "firstname", "Carl-Gustav");
	Item* lastname		= new StringItem(3, "lastname", "Bernadotte");

	Record* row		= new Record();
	row->add(id);
	row->add(username);
	row->add(firstname);
	row->add(lastname);

	Database* webshop	= new Database ("Webshop");
	Table* table		= new Table("login_credentials");
	webshop->addTable(table);

	if (addRecordToTable (webshop, "login_credentials", row)) {
		cout << "Row added!" << endl;
	} else {
		cout << "Error - Add row!" << endl;
	}

	BinaryDB binaryDB;
	binaryDB.createDatabase(webshop);

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

bool addRecordToTable (Database*& database, std::string tableName, Record* record) {
	try {
		Table* table 		= database->findTable(tableName);
		int* tableTypes 	= table->getItemTypes();
		int* recordTypes 	= record->getItemTypes();

		if (tableTypes != NULL) {
			cout << "Types:" << endl;
			for (int i = 0; i < record->getSize(); i++) {
					cout << tableTypes[i] << " - " << recordTypes[i] <<  endl;
			}
			table->add(record);
			return true;
		} else {
			table->add(record);
			return true;
		}
	} catch (char const* e) {}
	return false;
}

void printTable (Database* database, std::string tableName) {
	try {
		Table* table = database->findTable(tableName);
				

	} catch (char const* e) {}
}





























