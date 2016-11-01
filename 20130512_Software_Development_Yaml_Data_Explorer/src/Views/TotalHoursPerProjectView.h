#ifndef _VIEWS_TOTAL_HOURS_PER_PROJECT_CONTROLLER_H_
#define _VIEWS_TOTAL_HOURS_PER_PROJECT_CONTROLLER_H_

namespace Views {
  class TotalHoursPerProjectView : public ReportView {
    public:
      TotalHoursPerProjectView(Controller* controller);
      ~TotalHoursPerProjectView();
      void open();
      void close();
  };
}

#endif