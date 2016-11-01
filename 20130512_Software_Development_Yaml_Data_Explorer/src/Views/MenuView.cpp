#ifndef _VIEWS_MENU_VIEW_CPP_
#define _VIEWS_MENU_VIEW_CPP_
#include "OptionsView.cpp"
#include "MenuView.h"
using namespace Views;

MenuView::MenuView(Controller* controller) : OptionsView(controller, "Main Menu") {}
MenuView::~MenuView(){}
void MenuView::open(){
	this->getWindow()->open();
}
void MenuView::close(){
	this->getWindow()->close();
}
#endif