#ifndef _VIEWS_CONSOLE_OPTIONS_WINDOW_H_
#define _VIEWS_CONSOLE_OPTIONS_WINDOW_H_

namespace Views {
  class ConsoleOptionsWindow : public OptionsWindow {
  	public:
		ConsoleOptionsWindow(View* view);
		~ConsoleOptionsWindow();
		void open();
		void close();
  };
}

#endif