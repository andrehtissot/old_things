#ifndef _MODELS_LEGACY_ENTITY_LIST_CPP_
#define _MODELS_LEGACY_ENTITY_LIST_CPP_

#include "LegacyEntity.cpp"
#include "EntityList.cpp"
#include "LegacyEntityList.h"
using namespace Models;

LegacyEntityList::LegacyEntityList() : EntityList(){};
LegacyEntityList::~LegacyEntityList(){};

LegacyEntity* LegacyEntityList::findByLegacyId(std::string const legacyId) const{
	Utils::Lists::Iterator<Entity>* iterator = this->createIterator();
	LegacyEntity* currentLegacyEntity = dynamic_cast<LegacyEntity*>(iterator->getCurrentItem());
	while(currentLegacyEntity != NULL || iterator->hasNext()) {
		if(currentLegacyEntity!= NULL && (currentLegacyEntity->getLegacyId().compare(legacyId) == 0)){
			delete(iterator);
			return currentLegacyEntity;
		}
		iterator->next();
		currentLegacyEntity = dynamic_cast<LegacyEntity*>(iterator->getCurrentItem());
	}
	delete(iterator);
	return NULL;
}
void LegacyEntityList::removeByLegacyId(std::string const legacyId){
	Utils::Lists::Iterator<Entity>* iterator = this->createIterator();
	LegacyEntity* currentLegacyEntity = dynamic_cast<LegacyEntity*>(iterator->getCurrentItem());
	int currentIndex = 0;
	while(currentLegacyEntity != NULL || iterator->hasNext()) {
		if(currentLegacyEntity!= NULL && (currentLegacyEntity->getLegacyId().compare(legacyId) == 0)){
			this->remove(currentIndex);
			delete(iterator);
			return;
		}
		currentIndex++;
		iterator->next();
		currentLegacyEntity = dynamic_cast<LegacyEntity*>(iterator->getCurrentItem());
	}
	delete(iterator);
}
#endif