#ifndef _BINARY_DB_H
#define _BINARY_DB_H

#include "Database.h"
#include <string>

class BinaryDB {
	private:
		std::string name;
		Database** databases;

		int maxSize;
		int size;

		int findDatabase (std::string name);

	public:
		BinaryDB ();
		~BinaryDB ();
		
		bool createDatabase (std::string name);
		bool deleteDatabase (std::string name);
		bool databaseExist (std::string name);
		Database*& getDatabase (std::string name);

		std::string* listAllDatabases ();
		std::string* listTablesOfDatabase (std::string database);
		int getTableSizeOfDatabase (std::string database);

		bool createTableInDatabase(std::string database, std::string tableName);

		int getSize ();
		bool isEmpty ();

};

#endif // _BINARY_DB_H_
