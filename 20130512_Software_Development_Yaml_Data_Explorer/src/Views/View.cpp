#ifndef _VIEWS_VIEW_CPP_
#define _VIEWS_VIEW_CPP_
#include "../Utils/Options/Option.cpp"
#include "../Utils/TableData/TableData.cpp"
#include "View.h"
#include "../Controllers/Controller.cpp"
using namespace Views;

View::View(Controllers::Controller* controller, std::string const title)
 : title(title), controller(controller), window(NULL) {
 	this->options = this->controller->getOptions();
 	this->tableData = this->controller->getTableData();
};
View::~View(){
	if(NULL != this->window)
		delete(this->window);
};
const std::string View::getTitle() const{
	return this->title;
}
void View::setTitle(std::string const title){
	this->title = title;
}
std::list<Utils::Options::Option*>* View::getOptions() const{
	return this->options;
}
void View::setOptions(std::list<Utils::Options::Option*>* options){
	this->options = options;
}
std::vector<Utils::TableData::TableData*>* View::getTableData() const {
	return this->tableData;
}
void View::setTableData(std::vector<Utils::TableData::TableData*>* tableData){
	this->tableData = tableData;
}
Window* View::getWindow() {
	return this->window;
}
void View::setWindow(Window* const window){
	if(NULL != this->window)
		delete(this->window);
	this->window = window;
}
void View::selectOption(Utils::Options::Option* option){
	this->controller->selectOption(option);
}
#endif