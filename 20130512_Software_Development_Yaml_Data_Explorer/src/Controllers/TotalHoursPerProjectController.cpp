#ifndef _CONTROLLERS_TOTAL_HOURS_PER_PROJECT_CONTROLLER_CPP_
#define _CONTROLLERS_TOTAL_HOURS_PER_PROJECT_CONTROLLER_CPP_
#include <sstream>
#include "../Utils/Options/Option.cpp"
#include "Controller.cpp"
#include "../Views/TotalHoursPerProjectView.cpp"
#include "TotalHoursPerProjectController.h"
#include "../Utils/Lists/Iterator.h"
#include "../Models/ProjectEntity.cpp"
using namespace Controllers;

TotalHoursPerProjectController::TotalHoursPerProjectController() : Controller(){};
TotalHoursPerProjectController::TotalHoursPerProjectController(Controller* const caller) : Controller(caller) {};
TotalHoursPerProjectController::~TotalHoursPerProjectController(){};
void TotalHoursPerProjectController::openView(){
	this->getOptions()->push_back(new Option(0, "Go Back"));
	if(this->getView() == NULL) {
		this->setView(new TotalHoursPerProjectView(this));
		std::vector<Utils::TableData::TableData*>* tableData = this->getTableData();

		Utils::Lists::Iterator<Entity>* projectEntitiesIt = Main::getInstance()->getProjectEntityList()->createIterator();
		Entity* entity = projectEntitiesIt->getCurrentItem();
		int counter = 1;
		while(NULL != entity || projectEntitiesIt->hasNext()){
			if(NULL != entity){
				ProjectEntity* project = dynamic_cast<ProjectEntity*>(entity);
				float total = project->getTotalUsedHours();
				if(total >= 1){
					std::stringstream ss;
					ss << "Project nº " << counter++;
					tableData->push_back(new TableData(total, ss.str()));
				}		
			}
			projectEntitiesIt->next();
			entity = projectEntitiesIt->getCurrentItem();
		}
	}
	this->getView()->open();
}
void TotalHoursPerProjectController::closeView(){

}
void TotalHoursPerProjectController::selectOption(Utils::Options::Option* option){
	this->getView()->close();
	switch(option->getCode()){
		case 0:
			return;
	}
	this->getView()->open();
}
#endif