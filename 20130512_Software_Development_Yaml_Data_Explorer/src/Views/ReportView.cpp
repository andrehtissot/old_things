#ifndef _VIEWS_REPORT_VIEW_CPP_
#define _VIEWS_REPORT_VIEW_CPP_
#include "Window.cpp"
#include "View.cpp"
#include "ReportView.h"
using namespace Views;

ReportView::ReportView(Controller* controller, std::string const title) : View(controller, title) {};
ReportView::~ReportView(){};
Window* ReportView::getWindow() {
	if(NULL == this->window)
		this->window = WindowFactory::getInstance()->getReportWindow(this);
	return this->window;
}
#endif