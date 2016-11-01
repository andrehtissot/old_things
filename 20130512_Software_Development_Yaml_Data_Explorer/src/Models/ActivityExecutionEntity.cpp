#ifndef _MODELS_ACTIVITY_EXECUTION_ENTITY_CPP_
#define _MODELS_ACTIVITY_EXECUTION_ENTITY_CPP_
#include "../Utils/DateAndTime/DateTime.cpp"
#include "LegacyEntityList.cpp"
#include "LegacyEntity.cpp"
#include "ActivityExecutionEntity.h"
#include "ActivityEntity.cpp"
using namespace Models;

ActivityExecutionEntity::ActivityExecutionEntity() : LegacyEntity() {
	this->executerUserId = 0;
    this->executerUserLegacyId = "";
    this->executerUser = NULL;
    this->activityId = 0;
    this->activityLegacyId = "";
    this->activity = NULL;
    this->startedAt = NULL;
    this->endedAt = NULL;
};
ActivityExecutionEntity::ActivityExecutionEntity(int const id, std::string const legacyId, int const executerUserId, int const activityId, DateTime* const startedAt, DateTime* const endedAt)
	: LegacyEntity(id, legacyId) {
	this->executerUserId = executerUserId;
    this->executerUserLegacyId = "";
    this->executerUser = NULL;
    this->activityId = activityId;
    this->activityLegacyId = "";
    this->activity = NULL;
    this->startedAt = startedAt;
    this->endedAt = endedAt;
};
ActivityExecutionEntity::ActivityExecutionEntity(int const id, std::string const legacyId, std::string const executerUserLegacyId, std::string const activityLegacyId, DateTime* const startedAt, DateTime* const endedAt)
: LegacyEntity(id, legacyId) {
	this->executerUserId = 0;
    this->executerUserLegacyId = executerUserLegacyId;
    this->executerUser = NULL;
    this->activityId = 0;
    this->activityLegacyId = activityLegacyId;
    this->activity = NULL;
    this->startedAt = startedAt;
    this->endedAt = endedAt;
};
ActivityExecutionEntity::~ActivityExecutionEntity(){
	if(this->startedAt != NULL)
		delete(this->startedAt);
	if(this->endedAt != NULL)
		delete(this->endedAt);
};

const DateTime* ActivityExecutionEntity::getStartedAt() const{
	return this->startedAt;
}
void ActivityExecutionEntity::setStartedAt(DateTime* const startedAt){
	this->startedAt = startedAt;
}
const DateTime* ActivityExecutionEntity::getEndedAt() const{
	return this->endedAt;
}
void ActivityExecutionEntity::setEndedAt(DateTime* const endedAt){
	this->endedAt = endedAt;
}
UserEntity* ActivityExecutionEntity::getExecuterUser(){
	if(NULL == this->executerUser){
		if(this->executerUserLegacyId.compare("") != 0){
			LegacyEntity* legacyEntity = Main::getInstance()->getUserEntityList()->findByLegacyId(this->executerUserLegacyId);
			if(NULL != legacyEntity)
				this->executerUser = static_cast<UserEntity*>(legacyEntity);
		}
	}
	return this->executerUser;
}
void ActivityExecutionEntity::setExecuterUser(UserEntity* const executerUser){
	this->executerUser = executerUser;
}
ActivityEntity* ActivityExecutionEntity::getActivity() {
	if(NULL == this->activity){
		if(this->activityLegacyId.compare("") != 0){
			LegacyEntity* legacyEntity = Main::getInstance()->getActivityEntityList()->findByLegacyId(this->activityLegacyId);
			if(NULL != legacyEntity)
				this->activity = static_cast<ActivityEntity*>(legacyEntity);
		}
	}
	return this->activity;
}
void ActivityExecutionEntity::setActivity(ActivityEntity* const activity){
	this->activity = activity;
}
const int ActivityExecutionEntity::getExecuterUserId() const{
	return this->executerUserId;
}
void ActivityExecutionEntity::setExecuterUserId(int const executerUserId){
	this->executerUserId = executerUserId;
}
const std::string ActivityExecutionEntity::getExecuterUserLegacyId() const{
	return this->executerUserLegacyId;
}
void ActivityExecutionEntity::setExecuterUserLegacyId(std::string const executerUserLegacyId){
	this->executerUserLegacyId = executerUserLegacyId;
}
const int ActivityExecutionEntity::getActivityId() const{
	return this->activityId;
}
void ActivityExecutionEntity::setActivityId(int const activityId){
	this->activityId = activityId;
}
const std::string ActivityExecutionEntity::getActivityLegacyId() const{
	return this->activityLegacyId;
}
void ActivityExecutionEntity::setActivityLegacyId(std::string const activityLegacyId){
	this->activityLegacyId = activityLegacyId;
}

const float ActivityExecutionEntity::getSpentHours() const{
	if(NULL == this->getEndedAt() || NULL == this->getStartedAt())
		return 0.0f;
	float result = ((float) ((double) this->getEndedAt()->toHours() - (double) this->getStartedAt()->toHours()));
	return result < 0 ? -result : result;
}
#endif