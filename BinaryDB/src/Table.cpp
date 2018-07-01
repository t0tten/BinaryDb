#include "../include/Table.h"

Table::Table (std::string name) {
	this->name = name;
}

Table::~Table() {
}

std::string Table::getTableName () {
	return this->name;
}

void Table::setTableName (std::string name) {
	this->name = name;
}

void Table::add (Record* record) {
	this->records.add(record);
}

bool Table::remove (Record* record) {
	return this->records.remove (record);
}

Record*& Table::get (Record* record) {
	try {
		return this->records.find(record);
	} catch (char const* e) {
		throw e;
	}
}

std::string**& Table::getAllItemsAsStringArray () {
	std::string** strArr = new std::string*[this->records.size()];
	for (int i = 0; i < this->records.size(); i++) {
		strArr[i] = NULL;
	}

	Record** allRecords = this->records.getAllItemsAsArray();
	for (int i = 0; i < this->records.size(); i++) {
		strArr[i] = allRecords[i]->getItemAsStringArray ();
	}

	return strArr;
}

int* Table::getItemTypes () {
	Record* record = this->records.getFirst();
	return record->getItemTypes();	
}

int Table::getSize () {
	return this->records.size();
}
