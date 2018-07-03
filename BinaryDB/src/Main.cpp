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
bool assurance ();
void printHelpSection();

BinaryDB binaryDB;

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

bool findTask (vector<string> commands) {
	bool exit = false;
	
	if (commands.size() == 0) {
		// Do nothing
	} else if (commands.front() == "exit" || 
		(commands.front().length() == 1 && commands.front() == ".")) {
		
		exit = true;
	} else if (commands.front() == "help" || 
		(commands.front().length() == 1 && commands.front() == "?")) {
		
		printHelpSection();

	// Database stuf here
	} else if (commands.front().length() == 1 && commands.front() == "$") {
		
		// List all databases
		std::string* databases = binaryDB.listAllDatabases();
		if (databases != NULL)  {
			cout << "Databases:" << endl;
			for (int i = 0; i < binaryDB.getSize(); i++) {
				cout << "\t$" << databases[i] << endl;
			}
		} else {
			cout << "\t-> No databases exists" << endl;		
		}
	
		delete[] databases;
	} else if (commands.size() == 1 && 
			commands.front().length() > 1 && 
			commands.front()[0] == '$') {
		// Create databas	
		cout << "Create database " << commands.front() << "? (y/n): ";
		if (assurance()) { 
			if (binaryDB.createDatabase(commands.front().substr(1))) {
				cout << "\t-> Database " << commands.front() << " added" << endl;
			} else {
				cout << "\t-> Database " << commands.front() << " already exist" << endl;
			}
		}

	} else if (commands.size() == 1 && 
			commands.front().length() > 2 && 
			commands.front()[0] == '.' &&
			commands.front()[1] == '$') {
		// Delete database
		cout << "Delete database " << commands.front().substr(1) << "? (y/n): ";
		if (assurance()) {
			if (binaryDB.deleteDatabase(commands.front().substr(2))) {
				cout << "\t-> Database " << commands.front().substr(1) << " found" << endl;
				cout << "\t-> Database " << commands.front().substr(1) << " deleted" << endl;
			} else {
				cout << "\t-> Database " << commands.front().substr(1) << " does not exist" << endl;
			}
		}

	// Table stuf down here
	} else if (commands.size() == 2 && 
			commands.front().length() > 1 && 
			commands.front()[0] == '$' &&
			commands.at(1).length() == 1 &&
			commands.at(1)[0] == '#') {

		cout << "List tables (" << commands.front() << "):" << endl;
	} else if (commands.size() == 2 && 
			commands.front().length() > 1 && 
			commands.front()[0] == '$' &&
			commands.at(1).length() > 1 &&
			commands.at(1)[0] == '#') {
		
		cout << "Create table " << commands.at(1) << " (" << commands.front() << ")? (y/n): ";
		if (assurance()) { cout << "GO" << endl; }
	} else if (commands.size() == 2 && 
			commands.front().length() > 1 && 
			commands.front()[0] == '.' &&
			commands.front()[1] == '$' &&
			commands.at(1).length() > 1 &&
			commands.at(1)[0] == '#') {

		cout << "Delete table " << commands.at(1) << " (" << commands.front().substr(1) << ")? (y/n): ";
		if (assurance()) { cout << "GO" << endl; }
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
