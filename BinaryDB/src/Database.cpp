#include "../include/Database.h"

Database::Database (std::string name) {
	this->name = name;
	this->maxSize = 10;
	this->size = 0;

	this->tables = new Table*[this->maxSize];
	for (int i = 0; i < this->maxSize; i++) {
		this->tables[i] = NULL;
	}
}

Database::~Database () {
	for (int i = 0; i < this->size; i++) {
		delete this->tables[i];
	}
	delete[] this->tables;
}

std::string Database::getDatabaseName () {
	return this->name;
}

void Database::setDatabaseName (std::string name) {
	this->name = name;
}

int Database::getSize () {
	return this->size;
}

bool Database::isEmpty () {
	return this->size == 0;
}

void Database::addTable (Table* table) {
	if (this->size >= this->maxSize) {
		// new array
		this->maxSize *= 2;

		Table** _tmp = new Table*[this->maxSize];
		for (int i = 0; i < this->maxSize; i++) {
			_tmp[i] = NULL;
		}

		// copt old array
		for (int i = 0; i < this->size; i++) {
			_tmp[i] = this->tables[i];
			this->tables[i] = NULL;
		}

		delete[] this->tables;
		this->tables = _tmp;
	}

	this->tables[this->size] = table;
	this->size++;
}

void Database::addTable (std::string tableName) {
	Table* table = new Table(tableName);
	this->addTable(table);
}

bool Database::removeTable (std::string name) {
	int index = -1;
	for (int i = 0; i < this->size; i++) {
		if (this->tables[i]->getTableName() == name) {
			index = i;
			break;
		}
	}

	if (index != -1) {
		delete this->tables[index];
		this->tables[index] = this->tables[this->size - 1];
		this->tables[this->size - 1] = NULL;
		this->size--;
	}

	return false;
}

Table*& Database::tableAt (int index) {
	if (index >= 0 && index < this->size) {
		return this->tables[index];
	}
	throw "Index out ot bounds exception.";
}

Table*& Database::findTable (std::string name) {
	for (int i = 0; i < this->size; i++) {
		if (this->tables[i]->getTableName() == name) {
			return this->tables[i];
		}
	}
	throw "Index out ot bounds exception.";
}

std::string* Database::listTables () {
	if (this->size < 0) {
		return NULL;
	}
	std::string* tableNames = new std::string[this->size];
	for (int i = 0; i < this->size; i++) {
		tableNames[i] = std::to_string(i) + ": " + this->tables[i]->getTableName();
	}
	return tableNames;
}
