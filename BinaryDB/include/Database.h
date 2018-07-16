#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "../include/Table.h"

class Database {
	private:
		std::string name;
		Table** tables;
		
		int maxSize;
		int size;

	public:
		Database (std::string name);
		~Database ();

		std::string getDatabaseName ();
		void setDatabaseName (std::string);

		int getSize ();
		bool isEmpty ();

		void addTable (Table* table);
		void addTable (std::string tableName);
		bool removeTable (std::string name);

		Table*& tableAt (int index);
		Table*& findTable (std::string name);

		std::string* listTables ();

};

#endif // _DATABASE_H_
