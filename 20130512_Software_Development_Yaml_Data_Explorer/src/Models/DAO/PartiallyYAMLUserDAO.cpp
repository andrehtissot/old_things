#ifndef _MODELS_DAO_PARTIALLY_YAML_USER_DAO_CPP_
#define _MODELS_DAO_PARTIALLY_YAML_USER_DAO_CPP_
#include <fstream>
#include <iostream>
#include "PartiallyYAMLUserDAO.h"
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.cpp"
#include "BinaryUserDAO.cpp"
#include "../UserEntity.cpp"
using namespace Models::DAO;

PartiallyYAMLUserDAO::PartiallyYAMLUserDAO() : BinaryUserDAO(), PartiallyYAMLDAOSource("user.yml"){};
PartiallyYAMLUserDAO::~PartiallyYAMLUserDAO(){};
void PartiallyYAMLUserDAO::loadAllToList(EntityList* list){
	std::vector<std::string>* files = this->findFiles();
	int size = files->size();
	std::ifstream file;
	bool skipCreatedAt = false;
	bool skipUpdatedAt = false;
	for(int i = 0; i < size; i++){
		file.open (files->at(i).c_str());
		if (file.is_open()){
			std::string line;
			skipCreatedAt = false;
			skipUpdatedAt = false;
			UserEntity* user = new UserEntity();
			while (!file.eof()) {
				std::getline(file, line);
				if(line.compare(0, 3, "id:") == 0 && line.substr(4).compare("\"\"") != 0)
					user->setLegacyId(line.substr(4));
				if(line.compare(0, 5, "nome:") == 0 && line.substr(6).compare("\"\"") != 0)
					user->setName(line.substr(6));
				if(line.compare(0, 14, "ehProgramador:") == 0 && line.substr(15).compare("true") == 0)
				 	user->setIsDeveloper(true);
				if(line.compare(0, 18, "inicio_expediente:") == 0){
					Time* entryTime = new Time();
					entryTime->setHour(atoi(line.substr(19).c_str()));
					entryTime->setUTCHourOffset(-3); //Cwb - Brazil
					user->setEntryAt(entryTime);
				}
				if(line.compare(0, 15, "fim_expediente:") == 0){
					Time* departTime = new Time();
					departTime->setHour(atoi(line.substr(16).c_str()));
					departTime->setUTCHourOffset(-3); //Cwb - Brazil
					user->setDepartAt(departTime);
				}
				if(line.compare(0, 11, "updated_at:") == 0 && !skipUpdatedAt){
					DateTime* updateDateTime = new DateTime();
					if(line.compare(12, 3, "&id") == 0){
						skipCreatedAt = true;
						DateTime* createDateTime = new DateTime();
						createDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
						user->setCreatedAt(createDateTime);
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
					} else {
						updateDateTime->loadFromString(line.substr(12), "Y-m-d H:i:s.u P");
					}
					user->setUpdatedAt(updateDateTime);
				}
				if(line.compare(0, 11, "created_at:") == 0 && !skipCreatedAt){
					DateTime* createDateTime = new DateTime();
					if(line.compare(12, 3, "&id") == 0){
						skipUpdatedAt = true;
						DateTime* updateDateTime = new DateTime();
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
						user->setUpdatedAt(updateDateTime);
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
					} else {
						createDateTime->loadFromString(line.substr(12), "Y-m-d H:i:s.u P");
					}
					user->setCreatedAt(createDateTime);
				}
			}
			list->append(user);
			file.close();
		}
	}
	delete(files);
}

#endif