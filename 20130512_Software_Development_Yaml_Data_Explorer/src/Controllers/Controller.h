#ifndef _CONTROLLERS_CONTROLLER_H_
#define _CONTROLLERS_CONTROLLER_H_

namespace Controllers {
  class Controller {
    private:
      Controller* caller;
      Views::View* view;
      std::list<Utils::Options::Option*>* options;
      std::vector<Utils::TableData::TableData*>* tableData;
    protected:
      Controller();
      Controller(Controller* const caller);
    public:
      virtual ~Controller();
      const Controller* getCaller() const;
      std::list<Utils::Options::Option*>* getOptions() const;
      std::vector<Utils::TableData::TableData*>* getTableData() const;
      Views::View* getView() const;
      void setView(Views::View* const view);
      virtual void openView() = 0;
      virtual void closeView() = 0;
      virtual void selectOption(Utils::Options::Option* option);
  };
}

#endif