#include "../include/Record.h"
#include <iostream>

Record::Record (int compareIndex) {
	this->maxSize = 10;
	this->size = 0;
	this->compareIndex = compareIndex;

	this->record = new Item*[this->maxSize];
	for (int i = 0; i < this->maxSize; i++) {
		this->record[i] = NULL;
	}	
}

Record::~Record () {
	for (int i = 0; i < this->size; i++) {
		delete this->record[i];
	}

	delete[] this->record;
}

void Record::add (Item* item) {
	if (this->size >= this->maxSize) {
		// Resize array
		this->maxSize *= 2;
		Item** _tmp = new Item*[this->maxSize];
		
		for (int i = 0; i < this->maxSize; i++) {
			_tmp[i] = NULL;
		}

		// Copy old array
		for (int i = 0; i < this->size; i++) {
			_tmp[i] = this->record[i];
			this->record[i] = NULL;
		}

		delete[] this->record;
		this->record = _tmp;
	}

	this->record[this->size] = item;
	this->size++;
}

bool Record::_remove (int index) {
	if(index != -1) {
		delete this->record[index];
		this->record[index] = this->record[this->size - 1];
		this->record[this->size - 1] = NULL;
		this->size--;
		return true;
	} else {
		return false;
	}
}

bool Record::remove (int id) {
	int index = this->find(id);
	return this->_remove(index);
}

bool Record::remove (std::string name) {
	int index = this->find(name);
	return this->_remove(index);
}

bool Record::updateItem (int id, Item* item) {
	int index = this->find (id);
	if (index != -1) {
		delete this->record[index];
		this->record[index] = item;
		return true;
	} else {
		return false;
	}
}

int Record::find (Item* item) {
	// Do we need this?
	return -1;
}

int Record::find (int id) {
	for (int i = 0; i < this->size; i++) {
		if (this->record[i]->getId() == id) {
			return i;
		}
	}

	return -1;
}

int Record::find (std::string name) {
	for (int i = 0; i < this->size; i++) {
		if (this->record[i]->getName() == name) {
			return i;
		}
	}

	return -1;
}

void Record::print (int index) {
	std::cout << this->record[index]->toString() << std::endl;
}

Item*& Record::at (int index) {
	if (index >= 0 && index < this->size) {
		return this->record[index];
	}
	throw "Index out of bounds exception.";
}

int* Record::getItemTypes () {
	int* types = NULL;
	std::cout << "Record::getItemTypes()" << std::endl;
	if (this->size > 0) {
	std::cout << "Size if bugger then 0" << std::endl;
		types = new int[this->size];
		for (int i = 0; i < this->size; i++) {
			types[i] = this->record[i]->getType();	
		}
	}
	std::cout << "Returns" << std::endl;
	return types;
}

std::string* Record::getItemAsStringArray () const {
	std::string* strItems = NULL;
	
	if (this->size > 0) {
		strItems = new std::string[this->size];
		for (int i = 0; i < this->size; i++) {
			Item* item = this->record[i];
			if (StringItem* sItem = dynamic_cast<StringItem*>(item)) {
				strItems[i] = sItem->getName() + ":" + sItem->getItem();
			} else if (IntItem* iItem = dynamic_cast<IntItem*>(item)) {
				strItems[i] = iItem->getName() + ":" + std::to_string(iItem->getItem());
			} else if (DoubleItem* dItem = dynamic_cast<DoubleItem*>(item)) {
				strItems[i] = dItem->getName() + ":" + std::to_string(dItem->getItem());
			}
		}
	}
	return strItems;
}

int Record::getSize () { return this->size; }
bool Record::isEmpty () { return this->size == 0; }

bool Record::operator< (const Record*& rhs) {
	if (this->compareIndex < 0 || this->compareIndex > this->size) {
		this->compareIndex = 0;
	}

	Item* lhsItem = this->record[this->compareIndex];
	Item* rhsItem = rhs->record[this->compareIndex];

	if (StringItem* sLItem = dynamic_cast<StringItem*>(lhsItem)) {
		StringItem* sRItem = dynamic_cast<StringItem*>(rhsItem);
		return sLItem->getItem() < sRItem->getItem();

	} else if (IntItem* iLItem = dynamic_cast<IntItem*>(lhsItem)) {
		IntItem* iRItem = dynamic_cast<IntItem*>(rhsItem);
		return iLItem->getItem() < iRItem->getItem();
		
	} else if (DoubleItem* dLItem = dynamic_cast<DoubleItem*>(lhsItem)) {
		DoubleItem* dRItem = dynamic_cast<DoubleItem*>(rhsItem);
		return dLItem->getItem() < dRItem->getItem();

	}
	
}
bool Record::operator> (const Record*& rhs) { return !operator< (rhs); }
bool Record::operator<= (const Record*& rhs) { return !operator>(rhs); }
bool Record::operator>= (const Record*& rhs) { return operator<(rhs); }























