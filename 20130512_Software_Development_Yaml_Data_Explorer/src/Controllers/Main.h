#ifndef _CONTROLLERS_MAIN_H_
#define _CONTROLLERS_MAIN_H_
#include <iostream>
#include <cstring>
#include <string>

namespace Controllers {
  class MenuController;
  class Main {
    private:
      class MainDBManager {
        private:
          int sourceParameter;
          Models::DAO::DAOFactory* daoFactory;
        public:
          MainDBManager(const int sourceParameter = 0);
          ~MainDBManager();
          // const int getSourceParameter() const;
          // void setSourceParameter(const int sourceParameter);
          void setSourceParameter(const std::string sourceParameter);
          const bool isBinarySourceAvailable() const;
          const bool isYAMLSourceAvailable() const;
          // bool isAValidSourceParam(const std::string param);
          void loadDB();
          // void createOrOverwriteBinaryDB();
        private:
          void loadBinaryDB();
          void loadYAMLDB();
          void loadBinaryDBOnlyIfAvailable();
      };
      MainDBManager mainDBManager;
      static Main* mainInstance;
      LegacyEntityList* userEntityList;
      LegacyEntityList* projectEntityList;
      LegacyEntityList* activityEntityList;
      LegacyEntityList* activityExecutionEntityList;
      WindowFactory* windowFactory;
      MenuController* menuController;

    public:
      static Main* getInstance();
      Main();
      ~Main();
      LegacyEntityList* getUserEntityList();
      LegacyEntityList* getProjectEntityList();
      LegacyEntityList* getActivityEntityList();
      LegacyEntityList* getActivityExecutionEntityList();
      void setDBSourceParameter(const std::string parameter);
      void init();
      void loadDB();
    //   void createDBCache();
      void startMenu();
  };
}

#endif