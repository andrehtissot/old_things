#ifndef _MODELS_USER_ENTITY_CPP_
#define _MODELS_USER_ENTITY_CPP_
#include "../Utils/DateAndTime/DateTime.cpp"
#include "LegacyEntityList.cpp"
#include "LegacyEntity.cpp"
#include "UserEntity.h"
using namespace Models;

UserEntity::UserEntity() : LegacyEntity() {
	this->name = "";
	this->isDeveloper = false;
	this->entryAt = this->departAt = NULL;
	this->userActivitiesList =
	this->userExecutionsList =
	this->userProjectsList = NULL;
	this->createdAt = this->updatedAt = NULL;
};
UserEntity::UserEntity(int const id, std::string const legacyId, std::string const name, bool const isDeveloper, Time* const entryAt, Time* const departAt, DateTime* const createdAt, DateTime* const updatedAt)
	: LegacyEntity(id, legacyId) {
	this->name = name;
	this->isDeveloper = isDeveloper;
	this->entryAt = entryAt;
	this->departAt =  departAt;
	this->userActivitiesList =
	this->userExecutionsList =
	this->userProjectsList = NULL;
	this->createdAt = createdAt;
	this->updatedAt = updatedAt;
};
UserEntity::~UserEntity(){
	if(this->entryAt != NULL)
		delete(this->entryAt);
	if(this->departAt != NULL)
		delete(this->departAt);
	if(this->userActivitiesList != NULL)
		delete(this->userActivitiesList);
	if(this->userExecutionsList != NULL)
		delete(this->userExecutionsList);
	if(this->userProjectsList != NULL)
		delete(this->userProjectsList);
	if(this->createdAt != NULL)
		delete(this->createdAt);
	if(this->updatedAt != NULL)
		delete(this->updatedAt);
};
const std::string UserEntity::getName() const{
	return this->name;
}
void UserEntity::setName(std::string const name){
	this->name = name;
}
const bool UserEntity::getIsDeveloper() const{
	return this->isDeveloper;
}
void UserEntity::setIsDeveloper(bool const isDeveloper){
	this->isDeveloper = isDeveloper;
}
const Time* UserEntity::getEntryAt() const{
	return this->entryAt;
}
void UserEntity::setEntryAt(Time* const entryAt){
	this->entryAt = entryAt;
}
const Time* UserEntity::getDepartAt() const{
	return this->departAt;
}
void UserEntity::setDepartAt(Time* const departAt){
	this->departAt = departAt;
}
const DateTime* UserEntity::getCreatedAt() const{
	return this->createdAt;
}
void UserEntity::setCreatedAt(DateTime* const createdAt){
	this->createdAt = createdAt;
}
const DateTime* UserEntity::getUpdatedAt() const{
	return this->updatedAt;
}
void UserEntity::setUpdatedAt(DateTime* const updatedAt){
	this->updatedAt = updatedAt;
}
const LegacyEntityList* UserEntity::getActivitiesResponsible(){
	if(this->userActivitiesList == NULL){
		this->userActivitiesList = new LegacyEntityList();
		LegacyEntityList* activitiesList = Main::getInstance()->getActivityEntityList();
		Utils::Lists::Iterator<Entity>* it = activitiesList->createIterator();
		Entity* entity = it->getCurrentItem();
		ActivityEntity* activity = NULL;
		while(NULL != entity || it->hasNext()){
			if(NULL != entity){
				activity = dynamic_cast<ActivityEntity*>(entity);
				if(this->getLegacyId().compare(activity->getResponsibleLegacyId()) == 0)
					this->userActivitiesList->append(entity);
			}
			it->next();
			entity = it->getCurrentItem();
		}
		delete(it);
	}
	return this->userActivitiesList;
}
const LegacyEntityList* UserEntity::getActivityExecutions(){
	if(NULL == this->userExecutionsList){
		this->userExecutionsList = new LegacyEntityList();
		LegacyEntityList* activityExecutionsList = Main::getInstance()->getActivityExecutionEntityList();
		Utils::Lists::Iterator<Entity>* it = activityExecutionsList->createIterator();
		Entity* entity = it->getCurrentItem();
		ActivityExecutionEntity* execution = NULL;
		while(NULL != entity || it->hasNext()){
			if(NULL != entity){
				execution = dynamic_cast<ActivityExecutionEntity*>(entity);
				if(this->getLegacyId().compare(execution->getExecuterUserLegacyId()) == 0)
					this->userExecutionsList->append(entity);
			}
			it->next();
			entity = it->getCurrentItem();
		}
		delete(it);
	}
	return this->userExecutionsList;
}
const LegacyEntityList* UserEntity::getProjects(){
	return this->userProjectsList;
}
const float UserEntity::getTotalUsedHours() {
	float total = 0.0;
	Utils::Lists::Iterator<Entity>* it = this->getActivityExecutions()->createIterator();
	Entity* entity = it->getCurrentItem();
	ActivityExecutionEntity* execution = NULL;
	while(NULL != entity || it->hasNext()){
		if(NULL != entity){
			execution = dynamic_cast<ActivityExecutionEntity*>(entity);
			total += execution->getSpentHours();
		}
		it->next();
		entity = it->getCurrentItem();
	}
	delete(it);
	return total;
}
const float UserEntity::getTotalEstimatedHours() {
	float total = 0.0;
	LegacyEntityList* activitiesList = new LegacyEntityList();
	Utils::Lists::Iterator<Entity>* it = this->getActivityExecutions()->createIterator();
	Entity* entity = it->getCurrentItem();
	ActivityExecutionEntity* execution = NULL;
	ActivityEntity* activity = NULL;
	while(NULL != entity || it->hasNext()){
		if(NULL != entity){
			execution = dynamic_cast<ActivityExecutionEntity*>(entity);
			if(NULL == activitiesList->findByLegacyId(execution->getActivityLegacyId())){
				activity = execution->getActivity();
				total += activity->getTotalEstimatedHours();
				activitiesList->append(activity);
			}
		}
		it->next();
		entity = it->getCurrentItem();
	}
	delete(it);
	delete(activitiesList);
	return total;
}
#endif