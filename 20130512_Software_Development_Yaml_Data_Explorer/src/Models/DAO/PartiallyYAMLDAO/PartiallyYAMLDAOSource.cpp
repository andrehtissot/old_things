#ifndef _MODELS_DAO_PARTIALLY_YAML_DAO_PARTIALLY_YAML_DAO_SOURCE_CPP_
#define _MODELS_DAO_PARTIALLY_YAML_DAO_PARTIALLY_YAML_DAO_SOURCE_CPP_
#include "PartiallyYAMLDAOSource.h"
using namespace Models::DAO::PartiallyYAMLDAO;
#include "../../../Utils/FileSystem/Directory.cpp"

PartiallyYAMLDAOSource::PartiallyYAMLDAOSource(std::string const fileName){
	this->fileName = fileName;
}
PartiallyYAMLDAOSource::~PartiallyYAMLDAOSource(){}
const std::string PartiallyYAMLDAOSource::getFileName() const{
	return this->fileName;
}
void PartiallyYAMLDAOSource::setFileName(std::string const fileName){
	this->fileName = fileName;
}

std::vector<std::string>* PartiallyYAMLDAOSource::findFiles(){
	Directory* dir = new Directory("data/yaml");
	std::vector<std::string>* foundFiles = dir->findFilePaths(this->fileName);
	delete(dir);
	return foundFiles;
}

#endif