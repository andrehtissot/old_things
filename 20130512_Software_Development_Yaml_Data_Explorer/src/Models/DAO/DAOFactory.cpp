#ifndef _MODELS_DAO_DAO_FACTORY_CPP_
#define _MODELS_DAO_DAO_FACTORY_CPP_

#include "DAOFactory.h"
#include "../../Utils/DateAndTime/DateTime.cpp"
#include "../LegacyEntityList.cpp"
#include "BinaryDAO/BinaryDAOSource.cpp"
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.h"
#include "BinaryUserDAO.h"
#include "BinaryProjectDAO.h"
#include "BinaryActivityDAO.h"
#include "BinaryActivityExecutionDAO.h"
#include "PartiallyYAMLUserDAO.h"
#include "PartiallyYAMLProjectDAO.h"
#include "PartiallyYAMLActivityDAO.h"
#include "PartiallyYAMLActivityExecutionDAO.h"
#include "../../Controllers/Main.h"
#include "PartiallyYAMLUserDAO.cpp"
#include "PartiallyYAMLProjectDAO.cpp"
#include "PartiallyYAMLActivityDAO.cpp"
#include "PartiallyYAMLActivityExecutionDAO.cpp"
using namespace Models::DAO;


DAOFactory::DAOFactory(int source){
	this->source = source;
	this->activityDAO = NULL;
	this->userDAO = NULL;
	this->projectDAO = NULL;
	this->activityExecutionDAO = NULL;
}
DAOFactory::~DAOFactory(){
	if(this->activityDAO != NULL)
		delete(this->activityDAO);
	if(this->userDAO != NULL)
		delete(this->userDAO);
	if(this->projectDAO != NULL)
		delete(this->projectDAO);
	if(this->activityExecutionDAO != NULL)
		delete(this->activityExecutionDAO);
}
DAOFactory* DAOFactory::instance = 0;
DAOFactory* DAOFactory::getInstance(int source){
	if(DAOFactory::instance == 0){
		DAOFactory::instance = new DAOFactory(source);
	} else if(DAOFactory::instance->getSource() != source){
		delete(DAOFactory::instance);
		DAOFactory::instance = new DAOFactory(source);
	}
	return DAOFactory::instance;
}
const int DAOFactory::getSource() const {
	return this->source;
}
ActivityDAO* DAOFactory::getActivityDAO(){
	switch(this->source){
		case DAOFactory::PARTIALLY_YAML:
			if(this->activityDAO == NULL)
				this->activityDAO = new PartiallyYAMLActivityDAO();
			return this->activityDAO;
		case DAOFactory::BINARY:
			if(this->activityDAO == NULL)
			 	this->activityDAO = new BinaryActivityDAO();
			return this->activityDAO;
	}
	return NULL;
}
UserDAO* DAOFactory::getUserDAO(){
	switch(this->source){
		case DAOFactory::PARTIALLY_YAML:
			if(this->userDAO == NULL)
				this->userDAO = new PartiallyYAMLUserDAO();
			return this->userDAO;
		case DAOFactory::BINARY:
			if(this->userDAO == NULL)
			 	this->userDAO = new BinaryUserDAO();
			return this->userDAO;
	}
	return NULL;
}

ProjectDAO* DAOFactory::getProjectDAO(){
	switch(this->source){
		case DAOFactory::PARTIALLY_YAML:
			if(this->projectDAO == NULL)
				this->projectDAO = new PartiallyYAMLProjectDAO();
			return this->projectDAO;
		case DAOFactory::BINARY:
			if(this->projectDAO == NULL)
			 	this->projectDAO = new BinaryProjectDAO();
			return this->projectDAO;
	}
	return NULL;
}

ActivityExecutionDAO* DAOFactory::getActivityExecutionDAO(){
	switch(this->source){
		case DAOFactory::PARTIALLY_YAML:
			if(this->activityExecutionDAO == NULL)
				this->activityExecutionDAO = new PartiallyYAMLActivityExecutionDAO();
			return this->activityExecutionDAO;
		case DAOFactory::BINARY:
			if(this->activityExecutionDAO == NULL)
			 	this->activityExecutionDAO = new BinaryActivityExecutionDAO();
			return this->activityExecutionDAO;
	}
	return NULL;
}
#endif