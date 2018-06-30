#ifndef _STRING_ITEM_H_
#define _STRING_ITEM_H_

#include <unistd.h>
#include "Item.h"

class StringItem : public Item {
	private:
		std::string item;

		virtual std::string pToString();

	public:
		StringItem(int id, std::string name, std::string item);
		~StringItem();

		std::string getItem () const;
		void setItem (std::string item);
		
};

#endif // _STRING_ITEM_H_
