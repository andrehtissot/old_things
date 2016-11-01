#ifndef _VIEWS_VIEW_H_
#define _VIEWS_VIEW_H_

namespace Controllers {
  class Controller;
}

namespace Views {
  class View {
    private:
      std::string title;
      std::list<Utils::Options::Option*>* options;
      std::vector<Utils::TableData::TableData*>* tableData;
      Controllers::Controller* controller;
    protected:
      Window* window;
      View(Controllers::Controller* controller, std::string const title);
    public:
      virtual ~View();
      const std::string getTitle() const;
      void setTitle(std::string const title);
      std::list<Utils::Options::Option*>* getOptions() const;
      void setOptions(std::list<Utils::Options::Option*>* options);
      std::vector<Utils::TableData::TableData*>* getTableData() const;
      void setTableData(std::vector<Utils::TableData::TableData*>* tableData);
      virtual Window* getWindow() = 0;
      void setWindow(Window* const window);
      virtual void open() = 0;
      virtual void close() = 0;
      void selectOption(Utils::Options::Option* option);
  };
}

#endif