#include "../include/BinaryDB.h"

BinaryDB::BinaryDB () {
	this->name = "BinaryDB";
	this->size = 0;
	this->maxSize = 10;

	this->databases = new Database*[this->maxSize];
	for(int i = 0; i < this->maxSize; i++) {
		this->databases[i] = NULL;
	}
}

BinaryDB::~BinaryDB () {
	for (int i = 0; i < this->size; i++) {
		delete this->databases[i];
	}
	delete[] this->databases;
}

void BinaryDB::createDatabase (Database* database) {
	if (this->size >= this->maxSize) {
		// new array
		this->maxSize *= 2;

		Database** _tmp = new Database*[this->maxSize];
		for (int i = 0; i < this->maxSize; i++) {
			_tmp[i] = NULL;
		}

		// copy old
		for (int i = 0; i < this->size; i++) {
			_tmp[i] = this->databases[i];
			this->databases[i] = NULL;
		}

		delete[] this->databases;
		this->databases = _tmp;
	}

	this->databases[this->size] = database;
	this->size++;
}

bool BinaryDB::deleteDatabase (std::string name) {
	int index = this->findDatabase(name);

	if (index != -1) {
		return true;
	} else {
		return false;
	}
}

Database*& BinaryDB::getDatabase (std::string name) {
	int index = this->findDatabase(name);
	if (index != -1) {
		return this->databases[index];
	} else {
		throw "No database found exception";
	}
}

std::string* BinaryDB::listAllDatabases () {
	if (this->size > 0) {
		std::string* databaseNames = new std::string[this->size];
		for (int i =  0; i < this->size; i++) {
			databaseNames[i] = std::to_string(i) + ": " + this->databases[i]->getDatabaseName();
		}
		return databaseNames;
	}

	return NULL;
}

int BinaryDB::getSize () {
	return this->size;
}

bool BinaryDB::isEmpty () {
	return this->size == 0;
}

int BinaryDB::findDatabase (std::string name) {
	int index = -1;
	for (int i = 0; i < this->size; i++) {
		if (this->databases[i]->getDatabaseName() == name) {
			index = i;
			break;
		}
	}
	return index;
}

