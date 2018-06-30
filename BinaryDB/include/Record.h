#ifndef _RECORD_H_
#define _RECORD_H_

#include "StringItem.h"
#include "IntItem.h"
#include "DoubleItem.h"

class Record {
	private:
		int maxSize;
		int size;
		Item** record;

		bool _remove (int index);
	public:
		Record ();
		~Record ();

		void add (Item* item);
		bool remove (int id);
		bool remove (std::string name);
		bool updateItem (int id, Item* item);

		int find (Item* item);
		int find (int id);
		int find (std::string name);

		int getSize ();
		bool isEmpty ();
};

#endif // _RECORD_H_
