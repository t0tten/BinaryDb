#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <regex>

#include "../include/BinaryDB.h"

using namespace std;

void showLogo();
bool findTask(std::string input);
bool assurance ();
void printHelpSection();

void listDB();
void createDB(std::string database);
void deleteDB(std::string database);

void listTB(std::string database);
void createTB(std::string database, std::string tableName);
void deleteTB(std::string database, std::string tableName);


BinaryDB binaryDB;

int main() {
	showLogo();

	while (1) {
		cout << ":: ";
		std::string input = "";
		getline(cin, input);

		if (findTask(input)) return 0;
	}
}

void showLogo () {
	cout << "         _____                                ______  ______" << endl;
	cout << "        /  __ \\ .#$                          /  ___ \\/  __  \\" << endl;
	cout << "       /  /_/ /_________  ____  _____  __  __/  /  / /  /_/  /" << endl;
	cout << "      /     _//  /      \\/ __ \\/  __ \\/ /_/ /  /  /  /     _/" << endl;
	cout << "     /  __  \\/  /  __   / /_/ /  /_/_/____  /  /  / /  __  \\" << endl;
	cout << "    /  /_/  /  /  / /  / __  /  __  \\ ___/ /  /__/ /  /_/  /" << endl;
	cout << "   /_______/__/__/ /__/_/ /_/__/ /__//____/________/______/" << endl;
	cout << "                                           MUELLE v.1.0" << endl;
	cout << "  -------------------------------------------------------" << endl;
	cout << " -------------------------------------------------------" << endl <<  endl;
}

bool findTask (std::string input) {
	bool exit = false;
	istringstream iss(input);
	vector<string> commands {istream_iterator<string>(iss), istream_iterator<string>()};

	if (commands.size() == 0) {
	} else if (regex_match(input, regex("(exit|\\.)"))) {
		exit = true;
	} else if (regex_match(input, regex("(help|\\?)"))) {
		printHelpSection();
	} else if (regex_match(input, regex("[$]"))) {
		listDB();
	} else if (regex_match(input, regex("[$][a-zA-Z0-9]+"))) {
		createDB(commands.front());
	} else if (regex_match(input, regex("\\.[$][a-zA-Z0-9]+"))) {
		deleteDB(commands.front().substr(1));
	} else if (regex_match(input, regex("[$][a-zA-Z0-9]+ #"))) {
		listTB(commands.front());
	} else if (regex_match(input, regex("[$][a-zA-Z0-9]+ #[a-zA-Z0-9]+"))) {
		createTB(commands.front(), commands.at(1));
	} else if (regex_match(input, regex("\\.[$][a-zA-Z0-9]+ #[a-zA-Z0-9]+"))) {
		deleteTB(commands.front(), commands.at(1));
	} else {
		cout << " !!! invalid command !!!" << endl;
	}

	return exit;
}

bool assurance () {
	std::string input = "";
	getline(cin, input);

	if (input != "" && (input[0] == 'y' || input[0] == 'Y')) {
		return true;
	}

	return false;
}

void printHelpSection() {
	cout << endl;
	cout << "exit or .\t\t\t\texit program" << endl;
	cout << "help or ?\t\t\t\tshow this help section" << endl;
	cout << "$\t\t\t\t\tlist all databases" << endl;
	cout << "$<database name>\t\t\tcreate a new database" << endl;
	cout << ".$<database name>\t\t\tdeletes database" << endl;
	cout << endl;
	cout << "$<database name> #\t\t\tlists all tables after selection" << endl;
	cout << "$<database name> #<table name>\t\tcreate a new table in a database" << endl;
	cout << ".$<database name> #<table name>\t\tdelete a table from a database" << endl;
	cout << endl;
}

void listDB() {
	std::string* databases = binaryDB.listAllDatabases();
	if (databases != NULL)  {
		cout << "Databases:" << endl;
		for (int i = 0; i < binaryDB.getSize(); i++) {
			cout << "\t$" << databases[i] << endl;
		}
	} else {
		cout << "\t-> No databases exists." << endl;		
	}

	delete[] databases;
}

void createDB(std::string database) {
	cout << "Create database " << database << "? (y/n): ";
	if (assurance()) { 
		if (binaryDB.createDatabase(database.substr(1))) {
			cout << "\t-> Database " << database << " added." << endl;
		} else {
			cout << "\t-> Database " << database << " already exist." << endl;
		}
	}
}

void deleteDB(std::string database) {
	cout << "Delete database " << database << "? (y/n): ";
	if (assurance()) {
		if (binaryDB.deleteDatabase(database.substr(1))) {
			cout << "\t-> Database " << database << " found." << endl;
			cout << "\t-> Database " << database << " deleted." << endl;
		} else {
			cout << "\t-> Database " << database << " does not exist." << endl;
		}
	}
}

void listTB(std::string database) {
	cout << "List tables (" << database << "):" << endl;

	try {
		int tableSize = binaryDB.getTableSizeOfDatabase(database.substr(1));
		std::string* tableNames = binaryDB.listTablesOfDatabase(database.substr(1));
		if (tableSize > 0) {
			for (int i = 0; i < tableSize; i++) {
				cout << "\t#" << tableNames[i] << endl;
			}
			delete[] tableNames;
		} else {
			cout << "\t-> Database does not contain any tables." << endl;
		}

	} catch (const char* e) {
		cout << e << endl;
	}
}

void createTB(std::string database, std::string tableName) {
	cout << "Create table " << tableName << " (" << database << ")? (y/n): ";
	if (assurance()) { 
		try {
			if (binaryDB.createTableInDatabase(database.substr(1), tableName.substr(1))) {
				cout << "\t-> Table " << tableName << " created in database " << database << "!" << endl;
			} else {
				cout << "\t-> Table already exists" << endl;
			}
		} catch (const char* e) {
			cout << e << endl;
		}
	}
}

void deleteTB(std::string database, std::string tableName) {
	cout << "Delete table " << tableName << " (" << database.substr(1) << ")? (y/n): ";
	if (assurance()) {
		try {
			if(binaryDB.deleteTableFromDatabase(database.substr(2), tableName.substr(1))) {
				cout << "\t-> Table " << tableName << " has been deleted from " << database.substr(1) << "." << endl;
			} else {
				cout << "\t-> Table " << tableName << " in " << database.substr(1) << " not found." << endl;
			}
		} catch (const char* e) {
			cout << e << endl;
		}
	}
}
