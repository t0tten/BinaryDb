#ifndef _RECORD_H_
#define _RECORD_H_

#include "StringItem.h"
#include "IntItem.h"
#include "DoubleItem.h"
#include <iostream>

class Record {
	private:
		int compareIndex;
		int maxSize;
		int size;
		Item** record;
		
		bool _remove (int index);
	public:
		Record (int compareIndex);
		~Record ();

		void add (Item* item);
		bool remove (int id);
		bool remove (std::string name);
		bool updateItem (int id, Item* item);

		int find (Item* item);
		int find (int id);
		int find (std::string name);

		Item*& at (int index);
		void print (int index);
		
		int* getItemTypes();
		std::string* getItemAsStringArray () const;

		int getSize ();
		bool isEmpty ();

		bool operator< (const Record*& rhs);
		bool operator> (const Record*& rhs);
		bool operator<= (const Record*& rhs);
		bool operator>= (const Record*& rhs);
};

#endif // _RECORD_H_
