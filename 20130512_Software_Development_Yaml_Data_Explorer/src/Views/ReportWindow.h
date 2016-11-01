#ifndef _VIEWS_REPORT_WINDOW_H_
#define _VIEWS_REPORT_WINDOW_H_

namespace Views {
  class ReportWindow : public Window{
    protected:
		ReportWindow(View* view);
    public:
		virtual ~ReportWindow();
  };
}

#endif