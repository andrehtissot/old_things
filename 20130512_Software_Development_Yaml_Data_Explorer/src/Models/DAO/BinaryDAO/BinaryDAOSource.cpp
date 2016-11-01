#ifndef _MODELS_DAO_BINARY_DAO_BINARY_DAO_SOURCE_CPP_
#define _MODELS_DAO_BINARY_DAO_BINARY_DAO_SOURCE_CPP_

#include "BinaryDAOSource.h"
using namespace Models::DAO::BinaryDAO;

BinaryDAOSource::BinaryDAOSource(std::string const fileName){
	this->fileName = fileName;
}
BinaryDAOSource::~BinaryDAOSource(){}
const std::string BinaryDAOSource::getFileName() const{
	return this->fileName;
}
void BinaryDAOSource::setFileName(std::string const fileName){
	this->fileName = fileName;
}
#endif