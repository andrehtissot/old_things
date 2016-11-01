#ifndef _VIEWS_CONSOLE_OPTIONS_WINDOW_CPP_
#define _VIEWS_CONSOLE_OPTIONS_WINDOW_CPP_
#include <list>
#include <iostream>
#include <cstdio>
#include "../Utils/Options/Option.cpp"
#include "OptionsWindow.cpp"
#include "ConsoleOptionsWindow.h"
using namespace Views;

ConsoleOptionsWindow::ConsoleOptionsWindow(View* view)
 : OptionsWindow(view) {};
ConsoleOptionsWindow::~ConsoleOptionsWindow(){};
void ConsoleOptionsWindow::open(){
	Option* selectedOption = NULL;
	char selection;
	do {
		system("clear");
		std::cout << this->getView()->getTitle() << ':' << std::endl;
		std::list<Utils::Options::Option*>* options = this->getView()->getOptions();
		for (std::list<Utils::Options::Option*>::iterator it=options->begin(); it != options->end(); ++it)
			std::cout << ' ' << (*it)->getCode() << " - " << (*it)->getDescription() << std::endl;
		selection = getchar();
		for (std::list<Utils::Options::Option*>::iterator it=options->begin(); it != options->end(); ++it)
			if(selection == ('0' + (*it)->getCode())){
				selectedOption = (*it);
				break;
			}
	} while(NULL == selectedOption);
	this->getView()->selectOption(selectedOption);
}
void ConsoleOptionsWindow::close(){
	system("clear");
}
#endif