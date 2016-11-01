#ifndef _VIEWS_WINDOW_H_
#define _VIEWS_WINDOW_H_

namespace Views {
  class View;

  class Window {
  	private:
      View* view;
    public:
      Window(View* view);
      View* getView() const;
      void setView(View* const view);
      virtual ~Window();
      virtual void open() = 0;
      virtual void close() = 0;
  };
}

#endif