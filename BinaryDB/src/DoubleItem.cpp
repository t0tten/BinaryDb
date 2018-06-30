#include "../include/DoubleItem.h"

DoubleItem::DoubleItem (int id, std::string name, double item) : Item (id, name, Item::DBD_DOUBLE) {
	this->item = item;
}

DoubleItem::~DoubleItem () {
}

std::string DoubleItem::pToString() {
	return "Item: " + std::to_string(this->item);
}

double DoubleItem::getItem() const {
	return this->item;
}
