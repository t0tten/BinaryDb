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
}

bool Table::remove (Record* record) {
	return false;
}

Record*& get (int id) {
}

Record*& get (std::string name) {
}
