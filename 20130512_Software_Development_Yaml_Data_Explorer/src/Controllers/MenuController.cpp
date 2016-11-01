#ifndef _CONTROLLERS_MENU_CONTROLLER_CPP_
#define _CONTROLLERS_MENU_CONTROLLER_CPP_

#include "../Utils/Options/Option.cpp"
#include "Controller.cpp"
#include "../Views/MenuView.cpp"
#include "MenuController.h"
#include "TotalHoursPerProjectController.cpp"
using namespace Controllers;

MenuController::MenuController() : Controller(){};
MenuController::MenuController(Controller* const caller) : Controller(caller) {};
MenuController::~MenuController(){};
void MenuController::openView(){
	this->getOptions()->push_back(new Option(1, "Total Hours Per Project"));
	this->getOptions()->push_back(new Option(2, "Total Hours Per User"));
	this->getOptions()->push_back(new Option(3, "Total Hours Per Project Versus Estimated"));
	this->getOptions()->push_back(new Option(4, "Total Hours Per User Versus Estimated"));
	this->getOptions()->push_back(new Option(0, "Exit"));

	if(this->getView() == NULL)
		this->setView(new MenuView(this));
	this->getView()->open();
}
void MenuController::closeView(){
	this->getView()->close();
}
void MenuController::selectOption(Utils::Options::Option* option){
	this->getView()->close();
	switch(option->getCode()){
		case 1:
			this->openTotalHoursPerProjectController(); break;
		case 2:
			this->openTotalHoursPerUserController(); break;
		case 3:
			this->openTotalHoursPerProjectVersusEstimatedController(); break;
		case 4:
			this->openTotalHoursPerUserVersusEstimatedController(); break;
		case 0:
			return;
	}
	this->getView()->open();
}
void MenuController::openTotalHoursPerProjectController(){
	TotalHoursPerProjectController* totalHoursPerProjectController = new TotalHoursPerProjectController(this);
	(totalHoursPerProjectController)->openView();
	delete(totalHoursPerProjectController);
}
void MenuController::openTotalHoursPerUserController(){

}
void MenuController::openTotalHoursPerUserVersusEstimatedController(){

}
void MenuController::openTotalHoursPerProjectVersusEstimatedController(){

}
#endif