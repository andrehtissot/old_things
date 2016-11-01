#ifndef _MODELS_DAO_PARTIALLY_YAML_PROJECT_DAO_CPP_
#define _MODELS_DAO_PARTIALLY_YAML_PROJECT_DAO_CPP_
#include <fstream>
#include <iostream>
#include "PartiallyYAMLProjectDAO.h"
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.cpp"
#include "BinaryProjectDAO.cpp"
#include "../ProjectEntity.cpp"
using namespace Models::DAO;

PartiallyYAMLProjectDAO::PartiallyYAMLProjectDAO() : BinaryProjectDAO(), PartiallyYAMLDAOSource("project.yml"){};
PartiallyYAMLProjectDAO::~PartiallyYAMLProjectDAO(){};
void PartiallyYAMLProjectDAO::loadAllToList(EntityList* list){
	std::vector<std::string>* files = this->findFiles();
	int size = files->size();
	std::ifstream file;
	bool skipCreatedAt = false;
	bool skipUpdatedAt = false;
	std::vector<std::string>* legacyIds;
	for(int i = 0; i < size; i++){
		file.open (files->at(i).c_str());
		if (file.is_open()){
			std::string line;
			skipCreatedAt = false;
			skipUpdatedAt = false;
			ProjectEntity* project = new ProjectEntity();
			while (!file.eof()) {
				std::getline(file, line);

				if(line.compare(0, 3, "id:") == 0 && line.substr(4).compare("\"\"") != 0){
					project->setLegacyId(line.substr(4));
				} else if(line.compare(0, 6, "ativo:") == 0 && line.substr(7).compare("true") == 0){
				  	project->setIsActive(true);
				} else if(line.compare(0, 5, "nome:") == 0 && line.substr(6).compare("\"\"") != 0){
					project->setName(line.substr(6));
				} else if(line.compare(0, 11, "updated_at:") == 0 && !skipUpdatedAt){
					DateTime* updateDateTime = new DateTime();
					if(line.compare(12, 3, "&id") == 0){
						skipCreatedAt = true;
						DateTime* createDateTime = new DateTime();
						createDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
						project->setCreatedAt(createDateTime);
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
					} else {
						updateDateTime->loadFromString(line.substr(12), "Y-m-d H:i:s.u P");
					}
					project->setUpdatedAt(updateDateTime);
				} else if(line.compare(0, 11, "created_at:") == 0 && !skipCreatedAt){
					DateTime* createDateTime = new DateTime();
					if(line.compare(12, 3, "&id") == 0){
						skipUpdatedAt = true;
						DateTime* updateDateTime = new DateTime();
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
						project->setUpdatedAt(updateDateTime);
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
					} else {
						createDateTime->loadFromString(line.substr(12), "Y-m-d H:i:s.u P");
					}
					project->setCreatedAt(createDateTime);
				}
			}
			list->append(project);
			file.close();
		}
	}
	delete(files);
}

#endif