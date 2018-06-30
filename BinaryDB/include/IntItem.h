#ifndef _INT_ITEM_H_
#define _INT_ITEM_H_

#include <unistd.h>
#include "Item.h"

class IntItem : public Item {
	private:
		int item;

		virtual std::string pToString();

	public:
		IntItem(int id, std::string name, int item);
		~IntItem();

		int getItem () const;
		void setItem (int item);
		
};

#endif // _INT_ITEM_H_
