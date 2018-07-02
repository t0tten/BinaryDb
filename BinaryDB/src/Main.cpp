#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>

#include "../include/Tree.h"
#include "../include/StringItem.h"
#include "../include/IntItem.h"
#include "../include/DoubleItem.h"
#include "../include/Record.h"
#include "../include/Table.h"
#include "../include/Database.h"
#include "../include/BinaryDB.h"

using namespace std;

void showLogo();
bool findTask(vector<string> commands);
void printHelpSection();

void printStringArray (std::string* arr, int length);
bool addRecordToTable (Database*& database, std::string tableName, Record* record);

int main() {
	showLogo();

	while (1) {
		cout << ":: ";
		std::string input = "";
		getline(cin, input);

		istringstream iss(input);
		vector<string> commands {istream_iterator<string>(iss), istream_iterator<string>()};

		if (findTask(commands)) return 0;
	}

	Item* id 		= new IntItem(0, "id", 0);
	Item* username 		= new StringItem(1, "username", "MrBig");
	Item* firstname 	= new StringItem(2, "firstname", "Carl-Gustav");
	Item* lastname		= new StringItem(3, "lastname", "Bernadotte");

	Record* row		= new Record(22);
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

void showLogo () {
	cout << "         _____  ___                            ______  ______" << endl;
	cout << "        /  __ \\/__/                           /  ___ \\/  __  \\" << endl;
	cout << "       /  /_/ /_________  ____  _____  __  __/  /  / /  /_/  /" << endl;
	cout << "      /     _//  /      \\/ __ \\/  __ \\/ /_/ /  /  /  /     _/" << endl;
	cout << "     /  __  \\/  /  __   / /_/ /  /_/_/____  /  /  / /  __  \\" << endl;
	cout << "    /  /_/  /  /  / /  / __  /  __  \\ ___/ /  /__/ /  /_/  /" << endl;
	cout << "   /_______/__/__/ /__/_/ /_/__/ /__//____/________/______/" << endl;
	cout << "                                           MUELLE v.1.0" << endl;
	cout << "  -------------------------------------------------------" << endl;
	cout << " -------------------------------------------------------" << endl <<  endl;
}

bool findTask (vector<string> commands) {
	bool exit = false;
	if (commands.front() == "exit" || 
		(commands.front().length() == 1 && commands.front() == ".")) {
		
		exit = true;
	} else if (commands.front() == "help" || 
		(commands.front().length() == 1 && commands.front() == "?")) {
		
		printHelpSection();

	// Database stuf here
	} else if (commands.front().length() == 1 && commands.front() == "$") {
		
		cout << "List dbs" << endl;
	} else if (commands.size() == 1 && 
			commands.front().length() > 1 && 
			commands.front()[0] == '$') {
		
		cout << "Create db" << endl;
	} else if (commands.front() == "delete") {
	} else if (commands.size() == 1 && 
			commands.front().length() > 2 && 
			commands.front()[0] == '.' &&
			commands.front()[1] == '$') {
		
		cout << "Delete db" << endl;

	// Table stuf down here
	} else if (commands.front() == "list") {
		
		cout << "List stuf" << endl;
	}
	return exit;
}

void printHelpSection() {
	cout << endl;
	cout << "exit or .\t\t\t\texit program" << endl;
	cout << "help or ?\t\t\t\tshow this help section" << endl;
	cout << "$\t\t\t\t\tlist all databases" << endl;
	cout << "$<database name>\t\t\tcreate a new database" << endl;
	cout << ".$<database name>\t\t\tdeletes database" << endl;
	cout << endl;
	//cout << "select <database name>\t-\tselects a database" << endl;
	cout << "$<database name> #\t\t\tlists all tables after selection" << endl;
	cout << "$<database name> #<table name>\t\tcreate a new table in a database" << endl;
	cout << ".$<database name> #<table name>\t\tdelete a table from a database" << endl;
	cout << endl;
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
		try {
			int* tableTypes 	= table->getItemTypes();
			int* recordTypes 	= record->getItemTypes();

			cout << "Types:" << endl;
			for (int i = 0; i < record->getSize(); i++) {
					cout << tableTypes[i] << " - " << recordTypes[i] <<  endl;
			}
			table->add(record);
			return true;
		} catch (char const* e) {
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





























