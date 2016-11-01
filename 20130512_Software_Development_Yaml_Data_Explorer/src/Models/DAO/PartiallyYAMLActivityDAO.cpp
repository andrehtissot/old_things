#ifndef _MODELS_DAO_PARTIALLY_YAML_ACTIVITY_DAO_CPP_
#define _MODELS_DAO_PARTIALLY_YAML_ACTIVITY_DAO_CPP_
#include <fstream>
#include <iostream>
#include "PartiallyYAMLActivityDAO.h"
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.cpp"
#include "BinaryActivityDAO.cpp"
#include "../ActivityEntity.cpp"
using namespace Models::DAO;

PartiallyYAMLActivityDAO::PartiallyYAMLActivityDAO() : BinaryActivityDAO(), PartiallyYAMLDAOSource("card.yml"){};
PartiallyYAMLActivityDAO::~PartiallyYAMLActivityDAO(){};
void PartiallyYAMLActivityDAO::loadAllToList(EntityList* list){
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
			ActivityEntity* activity = new ActivityEntity();
			while (!file.eof()) {
				std::getline(file, line);
				if(line.compare(0, 11, "prioridade:") == 0)
					activity->setPriority(atoi(line.substr(12).c_str()));
				if(line.compare(0, 7, "titulo:") == 0 && line.substr(7).compare("\"\"") != 0){
					activity->setTitle(line.substr(8));
				}
				if(line.compare(0, 7, "status:") == 0) {
					if(line.substr(8).compare("nao_iniciado") == 0){
						activity->setStatus(ActivityEntity::STATUS_UNINITIATED);
					} else if(line.substr(8).compare("em_andamento") == 0){
						activity->setStatus(ActivityEntity::STATUS_ONGOING);
					} else if(line.substr(8).compare("finalizado") == 0){
						activity->setStatus(ActivityEntity::STATUS_FINALIZED);
					}
				}
				if(line.compare(0, 5, "tipo:") == 0) {
					if(line.substr(6).compare("historia") == 0){
						activity->setType(ActivityEntity::TYPE_REQUIREMENT);
					} else if(line.substr(6).compare("tarefa_desenvolvimento") == 0){
						activity->setType(ActivityEntity::TYPE_TEAM_TASK);
					} else if(line.substr(6).compare("detalhe") == 0){
						activity->setType(ActivityEntity::TYPE_DETAIL);
					} else if(line.substr(6).compare("bug") == 0){
						activity->setType(ActivityEntity::TYPE_SOFTWARE_BUG);
					} else if(line.substr(6).compare("bug_analise") == 0){
						activity->setType(ActivityEntity::TYPE_ANALYSIS_BUG);
					} else if(line.substr(6).compare("pendencia") == 0){
						activity->setType(ActivityEntity::TYPE_PENDENCY);
					}
				}
				if(line.compare(0, 10, "descricao:") == 0 && line.substr(11).compare("\"\"") != 0){
					activity->setDescription(line.substr(11));
				}
				if(line.compare(0, 11, "project_id:") == 0 && line.substr(12).compare("\"\"") != 0){
					activity->setProjectLegacyId(line.substr(12));
				}
				if(line.compare(0, 11, "updated_at:") == 0 && !skipUpdatedAt){
					DateTime* updateDateTime = new DateTime();
					if(line.compare(12, 3, "&id") == 0){
						skipCreatedAt = true;
						DateTime* createDateTime = new DateTime();
						createDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
						activity->setCreatedAt(createDateTime);
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
					} else {
						updateDateTime->loadFromString(line.substr(12), "Y-m-d H:i:s.u P");
					}
					activity->setUpdatedAt(updateDateTime);
				}
				if(line.compare(0, 11, "created_at:") == 0 && !skipCreatedAt){
					DateTime* createDateTime = new DateTime();
					if(line.compare(12, 3, "&id") == 0){
						skipUpdatedAt = true;
						DateTime* updateDateTime = new DateTime();
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
						activity->setUpdatedAt(updateDateTime);
						updateDateTime->loadFromString(line.substr(19), "Y-m-d H:i:s.u P");
					} else {
						createDateTime->loadFromString(line.substr(12), "Y-m-d H:i:s.u P");
					}
					activity->setCreatedAt(createDateTime);
				}
				if(line.compare(0, 3, "id:") == 0 && line.substr(4).compare("\"\"") != 0)
					activity->setLegacyId(line.substr(4));
				if(line.compare(0, 25, "carta_de_desenvolvimento:") == 0 && line.substr(25).compare("true"))
					activity->setIsDevelopment(true);
				if(line.compare(0, 15, "responsavel_id:") == 0 && line.substr(16).compare("\"\"") != 0)
					activity->setResponsibleLegacyId(line.substr(16));
				if(line.compare(0, 8, "esforco:") == 0){
					activity->setEffortEstimate(atof(line.substr(9).c_str()));
				}
			}
			list->append(activity);
			file.close();
		}
	}
	delete(files);
}

#endif