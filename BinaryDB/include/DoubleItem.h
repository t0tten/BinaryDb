#ifndef _DOUBLE_ITEM_H_
#define _DOUBLE_ITEM_H_

#include <unistd.h>
#include "Item.h"

class DoubleItem : public Item {
	private:
		double item;

		virtual std::string pToString();

	public:
		DoubleItem(int id, std::string name, double item);
		~DoubleItem();

		double getItem () const;
		void setItem (double item);
		
};

#endif // _DOUBLE_ITEM_H_
