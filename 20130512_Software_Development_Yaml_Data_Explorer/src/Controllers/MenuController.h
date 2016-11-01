#ifndef _CONTROLLERS_MENU_CONTROLLER_H_
#define _CONTROLLERS_MENU_CONTROLLER_H_

namespace Controllers {
  class MenuController : public Controller {
    public:
      MenuController();
      MenuController(Controller* const caller);
      ~MenuController();
      void openView();
      void closeView();
      void selectOption(Utils::Options::Option* option);
      void openTotalHoursPerProjectController();
      void openTotalHoursPerUserController();
      void openTotalHoursPerUserVersusEstimatedController();
      void openTotalHoursPerProjectVersusEstimatedController();
  };
}

#endif