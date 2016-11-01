#ifndef _VIEWS_CONSOLE_WINDOW_FACTORY_CPP_
#define _VIEWS_CONSOLE_WINDOW_FACTORY_CPP_
#include "WindowFactory.cpp"
#include "ConsoleOptionsWindow.cpp"
#include "ConsoleReportWindow.cpp"
#include "ConsoleWindowFactory.h"
using namespace Views;

ConsoleWindowFactory::ConsoleWindowFactory(){}
ConsoleWindowFactory::~ConsoleWindowFactory(){}
OptionsWindow* ConsoleWindowFactory::getOptionsWindow(View* view){
	return new ConsoleOptionsWindow(view);
}
ReportWindow* ConsoleWindowFactory::getReportWindow(View* view){
	return new ConsoleReportWindow(view);
}
#endif