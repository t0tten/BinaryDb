#include "../include/IntItem.h"

IntItem::IntItem (int id, std::string name, int item) : Item (id, name, Item::DBD_INT) {
	this->item = item;
}

IntItem::~IntItem () {
}

std::string IntItem::pToString() {
	return "Item: " + std::to_string(this->item);
}

int IntItem::getItem() const {
	return this->item;
}
