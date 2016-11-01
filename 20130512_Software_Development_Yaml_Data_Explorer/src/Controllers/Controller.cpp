#ifndef _CONTROLLERS_CONTROLLER_CPP_
#define _CONTROLLERS_CONTROLLER_CPP_
#include <list>
#include "../Utils/Options/Option.cpp"
#include "../Utils/TableData/TableData.cpp"
#include "../Views/View.cpp"
#include "Controller.h"
using namespace Controllers;

Controller::Controller()
 : view(NULL), caller(NULL) {
 	this->options = new std::list<Utils::Options::Option*>();
 	this->tableData = new std::vector<Utils::TableData::TableData*>();
 };
Controller::Controller(Controller* const caller) 
 : view(NULL), caller(caller) {
 	this->options = new std::list<Utils::Options::Option*>();
 	this->tableData = new std::vector<Utils::TableData::TableData*>();
};
Controller::~Controller(){
	if(NULL != this->view)
		delete(view);
	if(NULL != this->options){
		for (std::list<Utils::Options::Option*>::iterator it=this->options->begin(); it != this->options->end(); ++it)
    		delete(*it);
		delete(this->options);
	}
	if(NULL != this->tableData){
		for (std::vector<Utils::TableData::TableData*>::iterator it=this->tableData->begin(); it != this->tableData->end(); ++it)
    		delete(*it);
		delete(this->tableData);
	}
};
const Controller* Controller::getCaller() const{
	return this->caller;
};
std::list<Utils::Options::Option*>* Controller::getOptions() const{
	return this->options;
}
std::vector<Utils::TableData::TableData*>* Controller::getTableData() const{
	return this->tableData;
}
Views::View* Controller::getView() const{
	return this->view;
}
void Controller::setView(Views::View* const view){
	if(NULL != this->view)
		delete(this->view);
	this->view = view;
}
void Controller::selectOption(Utils::Options::Option* option){};
#endif