#ifndef _VIEWS_MENU_VIEW_H_
#define _VIEWS_MENU_VIEW_H_

namespace Views {
  class MenuView : public OptionsView {
    public:
      MenuView(Controller* controller);
      ~MenuView();
      void open();
      void close();
  };
}

#endif