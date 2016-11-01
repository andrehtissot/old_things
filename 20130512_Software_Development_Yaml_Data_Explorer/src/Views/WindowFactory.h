#ifndef _VIEWS_WINDOW_FACTORY_H_
#define _VIEWS_WINDOW_FACTORY_H_

namespace Views {
  class ConsoleWindowFactory;

  class WindowFactory {
  	public:
  		static const short CONSOLE = 1;
  		static const short QT = 2;
    private:
  		static short presentationMode;
  		static WindowFactory* windowFactoryInstance;
    protected:
		  WindowFactory();
    public:
  		virtual ~WindowFactory();
  		static WindowFactory* getInstance();
  		static void setPresentationMode(short const presentationMode);
  		virtual OptionsWindow* getOptionsWindow(View* view);
  		virtual ReportWindow* getReportWindow(View* view);
  };
}

#endif