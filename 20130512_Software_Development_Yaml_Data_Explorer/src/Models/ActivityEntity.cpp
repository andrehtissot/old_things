#ifndef _MODELS_ACTIVITY_ENTITY_CPP_
#define _MODELS_ACTIVITY_ENTITY_CPP_
#include "../Utils/DateAndTime/DateTime.cpp"
#include "ActivityExecutionEntity.cpp"
#include "LegacyEntityList.cpp"
#include "LegacyEntity.cpp"
#include "ProjectEntity.cpp"
#include "UserEntity.cpp"
#include "ActivityEntity.h"
using namespace Models;

ActivityEntity::ActivityEntity() : LegacyEntity() {
	this->priority = this->status = this->type = 0;
    this->description = "";
    this->isDevelopment = false;
    this->effortEstimate = 0.0f;
    this->project = NULL;
    this->title = "";
    this->responsible = NULL;
    this->executionsList = NULL;
    this->createdAt = updatedAt = NULL;
	this->projectId = this->responsibleId = 0;
	this->projectLegacyId = "";
	this->responsibleLegacyId = "";
};
ActivityEntity::ActivityEntity(int const id, std::string const legacyId, int const priority, std::string const title, int const status, int const type, std::string const description, bool const isDevelopment, float const effortEstimate, int const projectId, int const responsibleId, DateTime* const createdAt, DateTime* const updatedAt)
	: LegacyEntity(id, legacyId) {
	this->priority = priority;
	this->status = status;
	this->type = type;
    this->title = title;
    this->description = description;
    this->isDevelopment = isDevelopment;
    this->effortEstimate = effortEstimate;
    this->project = NULL;
    this->responsible = NULL;
    this->executionsList = NULL;
	this->createdAt = createdAt;
	this->updatedAt = updatedAt;
	this->projectId = projectId;
	this->responsibleId = responsibleId;
	this->projectLegacyId = "";
	this->responsibleLegacyId = "";
};
ActivityEntity::ActivityEntity(int const id, std::string const legacyId, int const priority, std::string const title, int const status, int const type, std::string const description, bool const isDevelopment, float const effortEstimate, std::string const projectLegacyId, std::string const responsibleLegacyId, DateTime* const createdAt, DateTime* const updatedAt)
	: LegacyEntity(id, legacyId) {
	this->priority = priority;
	this->status = status;
	this->type = type;
    this->title = title;
    this->description = description;
    this->isDevelopment = isDevelopment;
    this->effortEstimate = effortEstimate;
    this->project = NULL;
    this->responsible = NULL;
    this->executionsList = NULL;
	this->createdAt = createdAt;
	this->updatedAt = updatedAt;
	this->projectId = this->responsibleId = 0;
	this->projectLegacyId = projectLegacyId;
	this->responsibleLegacyId = responsibleLegacyId;
};
ActivityEntity::~ActivityEntity(){
	if(this->executionsList != NULL)
		delete(this->executionsList);
	if(this->createdAt != NULL)
		delete(this->createdAt);
	if(this->updatedAt != NULL)
		delete(this->updatedAt);
};
const int ActivityEntity::getPriority() const{
	return this->priority;
}
void ActivityEntity::setPriority(int const priority){
	this->priority = priority;
}
const std::string ActivityEntity::getTitle() const{
	return this->title;
}
void ActivityEntity::setTitle(std::string const title){
	this->title = title;
}
const int ActivityEntity::getStatus() const{
	return this->status;
}
void ActivityEntity::setStatus(int const status){
	this->status = status;
}
const int ActivityEntity::getType() const{
	return this->type;
}
void ActivityEntity::setType(int const type){
	this->type = type;
}
const std::string ActivityEntity::getDescription() const{
	return this->description;
}
void ActivityEntity::setDescription(std::string const description){
	this->description = this->description;
}
const bool ActivityEntity::getIsDevelopment() const{
	return this->isDevelopment;
}
void ActivityEntity::setIsDevelopment(bool const isDevelopment){
	this->isDevelopment = isDevelopment;
}
const float ActivityEntity::getEffortEstimate() const{
	return effortEstimate;
}
void ActivityEntity::setEffortEstimate(float const effortEstimate){
	this->effortEstimate = effortEstimate;
}
const DateTime* ActivityEntity::getCreatedAt() const{
	return this->createdAt;
}
void ActivityEntity::setCreatedAt(DateTime* const createdAt){
	if(this->createdAt != NULL)
		delete(this->createdAt);
	this->createdAt = createdAt;
}
const DateTime* ActivityEntity::getUpdatedAt() const{
	return this->updatedAt;
}
void ActivityEntity::setUpdatedAt(DateTime* const updatedAt){
	if(this->updatedAt != NULL)
		delete(this->updatedAt);
	this->updatedAt = updatedAt;
}
ProjectEntity* ActivityEntity::getProject() {
	if(NULL == this->project){
		if(this->projectLegacyId.compare("") != 0){
			LegacyEntity* legacyEntity = Main::getInstance()->getProjectEntityList()->findByLegacyId(this->projectLegacyId);
			if(NULL != legacyEntity)
				this->project = static_cast<ProjectEntity*>(legacyEntity);
		}
	}
	return this->project;
}
void ActivityEntity::setProject(ProjectEntity* const project){
	this->project = project;
}
UserEntity* ActivityEntity::getResponsible() {
	if(NULL == this->responsible){
		if(this->responsibleLegacyId.compare("") != 0){
			LegacyEntity* legacyEntity = Main::getInstance()->getUserEntityList()->findByLegacyId(this->responsibleLegacyId);
			if(NULL != legacyEntity)
				this->responsible = static_cast<UserEntity*>(legacyEntity);
		}
	}
	return this->responsible;
}
void ActivityEntity::setResponsible(UserEntity* const responsible){
	this->responsible = responsible;
}
const int ActivityEntity::getProjectId() const{
	return this->projectId;
}
void ActivityEntity::setProjectId(int const projectId){
	this->projectId = projectId;
}
const std::string ActivityEntity::getProjectLegacyId() const{
	return this->projectLegacyId;
}
void ActivityEntity::setProjectLegacyId(std::string const projectLegacyId){
	this->projectLegacyId = projectLegacyId;
}
const int ActivityEntity::getResponsibleId() const {
	return this->responsibleId;
}
void ActivityEntity::setResponsibleId(int const responsibleId){
	this->responsibleId = responsibleId;
}
const std::string ActivityEntity::getResponsibleLegacyId() const{
	return this->responsibleLegacyId;
}
void ActivityEntity::setResponsibleLegacyId(std::string const responsibleLegacyId){
	this->responsibleLegacyId = responsibleLegacyId;
}
const LegacyEntityList* ActivityEntity::getActivityExecutions(){
	if(NULL == this->executionsList){
		this->executionsList = new LegacyEntityList();
		LegacyEntityList* activityExecutionsList = Main::getInstance()->getActivityExecutionEntityList();
		Utils::Lists::Iterator<Entity>* it = activityExecutionsList->createIterator();
		Entity* entity = it->getCurrentItem();
		ActivityExecutionEntity* execution = NULL;
		while(NULL != entity || it->hasNext()){
			if(NULL != entity){
				execution = dynamic_cast<ActivityExecutionEntity*>(entity);
				if(this->getLegacyId().compare(execution->getActivityLegacyId()) == 0)
					this->executionsList->append(entity);
			}
			it->next();
			entity = it->getCurrentItem();
		}
		delete(it);
	}
	return this->executionsList;
}
const float ActivityEntity::getTotalUsedHours(){
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
const float ActivityEntity::getTotalEstimatedHours(){
	return this->getEffortEstimate();
}

#endif