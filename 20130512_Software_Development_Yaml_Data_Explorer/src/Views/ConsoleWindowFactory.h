#ifndef _VIEWS_CONSOLE_WINDOW_FACTORY_H_
#define _VIEWS_CONSOLE_WINDOW_FACTORY_H_

namespace Views {
  class ConsoleWindowFactory : public WindowFactory {
    public:
		ConsoleWindowFactory();
		~ConsoleWindowFactory();
		OptionsWindow* getOptionsWindow(View* view);
		ReportWindow* getReportWindow(View* view);
  };
}

#endif