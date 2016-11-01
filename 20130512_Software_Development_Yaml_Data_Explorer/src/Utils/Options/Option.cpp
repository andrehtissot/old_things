#ifndef _UTILS_OPTIONS_OPTION_CPP_
#define _UTILS_OPTIONS_OPTION_CPP_
#include "Option.h"
using namespace Utils::Options;

Option::Option() : code(0), description("") {}
Option::Option(int const code, std::string const description)
  : code(code), description(description) {}
Option::~Option(){}
const int Option::getCode() const{
	return this->code;
}
void Option::setCode(int const code){
	this->code = code;
}
const std::string Option::getDescription() const{
	return this->description;
}
void Option::setDescription(std::string const description){
	this->description = description;
}
#endif