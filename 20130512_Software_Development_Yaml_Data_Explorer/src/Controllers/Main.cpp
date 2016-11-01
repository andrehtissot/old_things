#ifndef _CONTROLLERS_MAIN_CPP_
#define _CONTROLLERS_MAIN_CPP_

#include "../Utils/FileSystem/Directory.cpp"
#include "../Models/EntityList.cpp"
#include "../Views/WindowFactory.cpp"
#include "../Models/DAO/DAOFactory.cpp"
#include "MenuController.cpp"
#include "Main.h"
using namespace Controllers;
#include "MainDBManager.cpp"

Main* Main::mainInstance = NULL;
Main::Main() :
  windowFactory(NULL), menuController(NULL) {
  this->activityEntityList = new LegacyEntityList();
  this->userEntityList = new LegacyEntityList();
  this->projectEntityList = new LegacyEntityList();
  this->activityExecutionEntityList = new LegacyEntityList();
  Main::mainInstance = this;
}
Main::~Main(){
  if(NULL != this->activityEntityList){
    this->activityEntityList->removeAll(true);
    delete(this->activityEntityList);
  }
  if(NULL != this->userEntityList){
    this->userEntityList->removeAll(true);
    delete(this->userEntityList);
  }
  if(NULL != this->projectEntityList){
    this->projectEntityList->removeAll(true);
    delete(this->projectEntityList);
  }
  if(NULL != this->activityExecutionEntityList){
    this->activityExecutionEntityList->removeAll(true);
    delete(this->activityExecutionEntityList);
  }
  if(NULL != this->windowFactory)
    delete(this->windowFactory);
  if(NULL != this->menuController)
    delete(this->menuController);
}
Main* Main::getInstance(){
  if(Main::mainInstance == NULL)
    Main::mainInstance = new Main();
  return Main::mainInstance;
}
LegacyEntityList* Main::getUserEntityList(){
  return this->userEntityList;
}
LegacyEntityList* Main::getProjectEntityList(){
  return this->projectEntityList;
}
LegacyEntityList* Main::getActivityEntityList(){
  return this->activityEntityList;
}
LegacyEntityList* Main::getActivityExecutionEntityList(){
  return this->activityExecutionEntityList;
}

void Main::setDBSourceParameter(const std::string parameter){
  this->mainDBManager.setSourceParameter(parameter);
}
void Main::init(){
  try {
    this->loadDB();
  } catch(char const* message) {
    std::cout << message << std::endl;
    return;
  }

  this->startMenu();
}
void Main::loadDB(){
   this->mainDBManager.loadDB();
}
void Main::startMenu(){
  WindowFactory::setPresentationMode(WindowFactory::CONSOLE);
  this->windowFactory = WindowFactory::getInstance();
  this->menuController = new MenuController();
  this->menuController->openView();
}
#endif