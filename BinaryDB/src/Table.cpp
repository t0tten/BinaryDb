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

int Table::getSize () {
	return this->records.size();
}
