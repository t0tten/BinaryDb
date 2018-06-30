#ifndef _TABLE_H_
#define _TABLE_H_

#include <string>
#include "../include/Tree.h"
#include "../include/Record.h"

class Table {
	private:
		std::string name;
		Tree<Record*> record;
	public:
		Table(std::string name);
		~Table();

		std::string getTableName ();
		void setTableName (std::string name);	

		void add (Record* record);
		bool remove (Record* record);

		Record*& get (int id);
		Record*& get (std::string name);
};

#endif // _TABLE_H_
