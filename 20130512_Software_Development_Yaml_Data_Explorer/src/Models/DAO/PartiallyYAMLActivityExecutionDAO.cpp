#ifndef _MODELS_DAO_PARTIALLY_YAML_ACTIVITY_EXECUTION_DAO_CPP_
#define _MODELS_DAO_PARTIALLY_YAML_ACTIVITY_EXECUTION_DAO_CPP_
#include <fstream>
#include "PartiallyYAMLActivityExecutionDAO.h"
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.cpp"
#include "BinaryActivityExecutionDAO.cpp"
#include "../ActivityExecutionEntity.cpp"
using namespace Models::DAO;

PartiallyYAMLActivityExecutionDAO::PartiallyYAMLActivityExecutionDAO() : BinaryActivityExecutionDAO(), PartiallyYAMLDAOSource("card.yml"){};
PartiallyYAMLActivityExecutionDAO::~PartiallyYAMLActivityExecutionDAO(){};
void PartiallyYAMLActivityExecutionDAO::loadAllToList(EntityList* list){
	std::vector<std::string>* files = this->findFiles();
	EntityList* preList = new EntityList();
	int size = files->size();
	std::ifstream file;
	for(int i = 0; i < size; i++){
		file.open (files->at(i).c_str());
		if (file.is_open()){
			std::string line;
			ActivityExecutionEntity* activityExecution = NULL;
			std::string activityLegacyId = "";
			DateTime* startedDateTime = NULL;
			DateTime* endedDateTime = NULL;
			std::string executerUserLegacyId = "";
			while (!file.eof()) {
				std::getline(file, line);
				if(startedDateTime != NULL && endedDateTime != NULL && executerUserLegacyId.compare("") != 0){
					activityExecution = new ActivityExecutionEntity();
					activityExecution->setExecuterUserLegacyId(executerUserLegacyId);
					activityExecution->setStartedAt(startedDateTime);
					activityExecution->setEndedAt(endedDateTime);
					preList->append(activityExecution);
					startedDateTime = endedDateTime = NULL;
					executerUserLegacyId = "";
				}
				if(line.compare(0, 10, "  user_id:") == 0){
					executerUserLegacyId = line.substr(11);
				}
				if(line.compare(0, 14, "  iniciado_em:") == 0){
					if(startedDateTime != NULL)
						delete(startedDateTime);
					startedDateTime = new DateTime();
					startedDateTime->loadFromString(line.substr(15), "Y-m-d H:i:s.u P");
				}
				if(line.compare(0, 16, "  finalizado_em:") == 0){
					if(endedDateTime != NULL)
						delete(endedDateTime);
					endedDateTime = new DateTime();
					endedDateTime->loadFromString(line.substr(17), "Y-m-d H:i:s.u P");
				}
				if(line.compare(0, 3, "id:") == 0 && line.substr(4).compare("\"\"") != 0)
					activityLegacyId = line.substr(4);
			}
			if(startedDateTime != NULL)
				delete(startedDateTime);
			if(endedDateTime != NULL)
				delete(endedDateTime);
			file.close();

			Utils::Lists::Iterator<Entity>* iterator = preList->createIterator();
			Entity* currentItem = iterator->getCurrentItem();
			int currentPosition = 1;
			while(currentItem != NULL || iterator->hasNext()) {
				if(currentItem != NULL) {
					activityExecution = static_cast<ActivityExecutionEntity*>(currentItem);
					activityExecution->setActivityLegacyId(activityLegacyId);
					std::stringstream ss;
					ss << activityLegacyId << currentPosition;
					activityExecution->setLegacyId(ss.str());
					list->append(currentItem);
				}
				iterator->next();
				currentItem = iterator->getCurrentItem();
			}
			delete(iterator);
			preList->removeAll();
		}
	}
	delete(files);
	delete(preList);
}

#endif