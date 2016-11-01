#ifndef _VIEWS_WINDOW_FACTORY_CPP_
#define _VIEWS_WINDOW_FACTORY_CPP_
#include "Window.cpp"
#include "OptionsWindow.cpp"
#include "ReportWindow.cpp"
#include "WindowFactory.h"
#include "ConsoleWindowFactory.cpp"
using namespace Views;

short WindowFactory::presentationMode = 0;
WindowFactory* WindowFactory::windowFactoryInstance = NULL;

WindowFactory::WindowFactory(){}
WindowFactory::~WindowFactory(){}
WindowFactory* WindowFactory::getInstance(){
	if(NULL == WindowFactory::windowFactoryInstance)
		WindowFactory::windowFactoryInstance = new ConsoleWindowFactory();
	return WindowFactory::windowFactoryInstance;
}
void WindowFactory::setPresentationMode(short const presentationMode){
	WindowFactory::presentationMode = presentationMode;
}
OptionsWindow* WindowFactory::getOptionsWindow(View* view){}
ReportWindow* WindowFactory::getReportWindow(View* view){}
#endif