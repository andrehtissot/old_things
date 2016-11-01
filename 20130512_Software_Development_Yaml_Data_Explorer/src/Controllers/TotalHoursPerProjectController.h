#ifndef _CONTROLLERS_TOTAL_HOURS_PER_PROJECT_CONTROLLER_H_
#define _CONTROLLERS_TOTAL_HOURS_PER_PROJECT_CONTROLLER_H_

namespace Controllers {
  class TotalHoursPerProjectController : public Controller {
    public:
      TotalHoursPerProjectController();
      TotalHoursPerProjectController(Controller* const caller);
      ~TotalHoursPerProjectController();
      void openView();
      void closeView();
      void selectOption(Utils::Options::Option* option);
  };
}

#endif