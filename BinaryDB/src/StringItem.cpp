#include "../include/StringItem.h"

StringItem::StringItem (int id, std::string name, std::string item) : Item (id, name, Item::DBD_STRING) {
	this->item = item;
}

StringItem::~StringItem () {
}

std::string StringItem::pToString() {
	return "Item: " + this->item;
}

std::string StringItem::getItem() const {
	return this->item;
}
