#ifndef _VIEWS_CONSOLE_REPORT_WINDOW_H_
#define _VIEWS_CONSOLE_REPORT_WINDOW_H_

namespace Views {
  class ConsoleReportWindow : public ReportWindow {
  	public:
		ConsoleReportWindow(View* view);
		~ConsoleReportWindow();
		void open();
		void close();
  };
}

#endif