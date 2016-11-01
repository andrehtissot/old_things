#ifndef _VIEWS_OPTIONS_VIEW_CPP_
#define _VIEWS_OPTIONS_VIEW_CPP_
#include "Window.cpp"
#include "View.cpp"
#include "OptionsView.h"
using namespace Views;

OptionsView::OptionsView(Controller* controller, std::string const title) : View(controller, title) {};
OptionsView::~OptionsView(){};
Window* OptionsView::getWindow() {
	if(NULL == this->window)
		this->window = WindowFactory::getInstance()->getOptionsWindow(this);
	return this->window;
}
#endif