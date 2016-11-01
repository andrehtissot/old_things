#ifndef _MODELS_PROJECT_ENTITY_CPP_
#define _MODELS_PROJECT_ENTITY_CPP_
#include <string>
#include <vector>
#include "../Utils/DateAndTime/DateTime.cpp"
#include "LegacyEntityList.cpp"
#include "LegacyEntity.cpp"
#include "ProjectEntity.h"
using namespace Models;

ProjectEntity::ProjectEntity() : LegacyEntity() {
	this->name = "";
	this->isActive = false;
	this->projectActivitiesList = NULL;
	this->createdAt = this->updatedAt = NULL;
};
ProjectEntity::ProjectEntity(int const id, std::string const legacyId, std::string const name, bool const isActive, DateTime* const createdAt, DateTime* const updatedAt)
	: LegacyEntity(id, legacyId) {
	this->name = name;
	this->isActive = isActive;
	this->projectActivitiesList = NULL;
	this->createdAt = createdAt;
	this->updatedAt = updatedAt;
};
ProjectEntity::~ProjectEntity(){
	if(this->projectActivitiesList != NULL)
		delete(this->projectActivitiesList);
	if(this->createdAt != NULL)
		delete(this->createdAt);
	if(this->updatedAt != NULL)
		delete(this->updatedAt);
};
const std::string ProjectEntity::getName() const{
	return this->name;
}
void ProjectEntity::setName(std::string const name){
	this->name = name;
}
const bool ProjectEntity::getIsActive() const{
	return this->isActive;
}
void ProjectEntity::setIsActive(bool const isActive){
	this->isActive = isActive;
}
const DateTime* ProjectEntity::getCreatedAt() const{
	return this->createdAt;
}
void ProjectEntity::setCreatedAt(DateTime* const createdAt){
	this->createdAt = createdAt;
}
const DateTime* ProjectEntity::getUpdatedAt() const{
	return this->updatedAt;
}
void ProjectEntity::setUpdatedAt(DateTime* const updatedAt){
	this->updatedAt = updatedAt;
}

const LegacyEntityList* ProjectEntity::getActivities(){
	if(NULL == this->projectActivitiesList){
		this->projectActivitiesList = new LegacyEntityList();
		LegacyEntityList* activitiesList = Main::getInstance()->getActivityEntityList();
		Utils::Lists::Iterator<Entity>* it = activitiesList->createIterator();
		Entity* entity = it->getCurrentItem();
		ActivityEntity* activity = NULL;
		while(NULL != entity || it->hasNext()){
			if(NULL != entity){
				activity = dynamic_cast<ActivityEntity*>(entity);
				if(this->getLegacyId().compare(activity->getProjectLegacyId()) == 0)
					this->projectActivitiesList->append(entity);
			}
			it->next();
			entity = it->getCurrentItem();
		}
		delete(it);
	}
	return this->projectActivitiesList;
}
const float ProjectEntity::getTotalUsedHours() {
	float total = 0.0;
	Utils::Lists::Iterator<Entity>* it = this->getActivities()->createIterator();
	Entity* entity = it->getCurrentItem();
	ActivityEntity* activity = NULL;
	while(NULL != entity || it->hasNext()){
		if(NULL != entity){
			activity = dynamic_cast<ActivityEntity*>(entity);
			total += activity->getTotalUsedHours();
		}
		it->next();
		entity = it->getCurrentItem();
	}
	delete(it);
	return total;
}
const float ProjectEntity::getTotalEstimatedHours() {
	float total = 0.0;
	Utils::Lists::Iterator<Entity>* it = this->getActivities()->createIterator();
	Entity* entity = it->getCurrentItem();
	ActivityEntity* activity = NULL;
	while(NULL != entity || it->hasNext()){
		if(NULL != entity){
			activity = dynamic_cast<ActivityEntity*>(entity);
			total += activity->getTotalEstimatedHours();
		}
		it->next();
		entity = it->getCurrentItem();
	}
	delete(it);
	return total;
}
#endif