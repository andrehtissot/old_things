#ifndef _VIEWS_WINDOW_CPP_
#define _VIEWS_WINDOW_CPP_
#include "../Utils/Options/Option.cpp"
#include "Window.h"
#include "View.cpp"
using namespace Views;

Window::Window(View* view) : view(view){};
Window::~Window(){};
View* Window::getView() const{
	return this->view;
}
void Window::setView(View* const view){
	this->view = view;
}
#endif