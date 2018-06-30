#include "../include/Record.h"

Record::Record () {
	this->maxSize = 10;
	this->size = 0;

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

int Record::getSize () { return this->size; }
bool Record::isEmpty () { return this->size == 0; }

