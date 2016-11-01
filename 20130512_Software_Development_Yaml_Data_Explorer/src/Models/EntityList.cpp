#ifndef _MODELS_ENTITY_LIST_CPP_
#define _MODELS_ENTITY_LIST_CPP_

#include "../Utils/Lists/LinkedList.h"
#include "Entity.cpp"
#include "EntityList.h"
using namespace Models;

EntityList::EntityList() : LinkedList <Entity>() {};
EntityList::~EntityList(){};
Entity* EntityList::findById(int const id) {
	Utils::Lists::Iterator<Entity>* iterator = this->createIterator();
	Entity* currentEntity = iterator->getCurrentItem();
	while(currentEntity != NULL || iterator->hasNext()) {
		if(currentEntity!= NULL && currentEntity->getId() == id){
			delete(iterator);
			return currentEntity;
		}
		iterator->next();
		currentEntity = iterator->getCurrentItem();
	}
	delete(iterator);
	return NULL;
}
void EntityList::removeById(int const id){
	Utils::Lists::Iterator<Entity>* iterator = this->createIterator();
	Entity* currentEntity = iterator->getCurrentItem();
	int currentIndex = 0;
	while(currentEntity != NULL || iterator->hasNext()) {
		if(currentEntity!= NULL && currentEntity->getId() == id){
			this->remove(currentIndex);
			delete(iterator);
			return;
		}
		currentIndex++;
		iterator->next();
		currentEntity = iterator->getCurrentItem();
	}
	delete(iterator);
}
#endif