#ifndef _VIEWS_CONSOLE_REPORT_WINDOW_CPP_
#define _VIEWS_CONSOLE_REPORT_WINDOW_CPP_
#include <list>
#include <iostream>
#include <cstdio>
#include "../Utils/Options/Option.cpp"
#include "ReportWindow.cpp"
#include "ConsoleReportWindow.h"
using namespace Views;

ConsoleReportWindow::ConsoleReportWindow(View* view)
 : ReportWindow(view) {};
ConsoleReportWindow::~ConsoleReportWindow(){};
void ConsoleReportWindow::open(){
	Utils::Options::Option* goBack = this->getView()->getOptions()->front();
	char selection;
	do {
		system("clear");
		std::cout << this->getView()->getTitle() << ':' << std::endl;

		std::vector<Utils::TableData::TableData*>* tableData = this->getView()->getTableData();
		for (std::vector<Utils::TableData::TableData*>::iterator it=tableData->begin(); it != tableData->end(); ++it)
			std::cout << ' ' << (*it)->getValue() << ((*it)->getValue() > 1 ? " hours" : " hour") << " spent on " << (*it)->getDescription() << std::endl;
			
		std::cout << std::endl << ' ' << goBack->getCode() << " - " << goBack->getDescription() << std::endl;
		selection = getchar();
	} while(selection != ('0'+goBack->getCode()));
	this->getView()->selectOption(goBack);
}
void ConsoleReportWindow::close(){
	system("clear");
}
#endif