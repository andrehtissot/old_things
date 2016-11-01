#ifndef _VIEWS_TOTAL_HOURS_PER_PROJECT_CONTROLLER_CPP_
#define _VIEWS_TOTAL_HOURS_PER_PROJECT_CONTROLLER_CPP_
#include "ReportView.cpp"
#include "TotalHoursPerProjectView.h"
using namespace Views;

TotalHoursPerProjectView::TotalHoursPerProjectView(Controller* controller) : ReportView(controller, "Total Hours Per Project") {}
TotalHoursPerProjectView::~TotalHoursPerProjectView(){}
void TotalHoursPerProjectView::open(){
	this->getWindow()->open();
}
void TotalHoursPerProjectView::close(){
	this->getWindow()->close();
}
#endif