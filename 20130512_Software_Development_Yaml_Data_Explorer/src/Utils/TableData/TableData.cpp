#ifndef _UTILS_TABLE_DATA_TABLE_DATA_CPP_
#define _UTILS_TABLE_DATA_TABLE_DATA_CPP_
#include "TableData.h"
using namespace Utils::TableData;

TableData::TableData() : value(0), description("") {}
TableData::TableData(int const value, std::string const description)
 : value(value), description(description) {}
TableData::~TableData(){}
const std::string TableData::getDescription() const {
	return this->description;
}
void TableData::setDescription(std::string const description){
	this->description = description;
}
const float TableData::getValue() const {
	return this->value;
}
void TableData::setValue(float const value){
	this->value = value;
}
#endif