#ifndef _MODELS_DAO_DAO_FACTORY_H_
#define _MODELS_DAO_DAO_FACTORY_H_

namespace Models {
  namespace DAO {
    class ActivityDAO;
    class UserDAO;
    class ProjectDAO;
    class ActivityExecutionDAO;

    class DAOFactory {
      public:
        static const int PARTIALLY_YAML = 1;
        static const int BINARY = 2;
        static DAOFactory* instance;

      private:
        int source;
        ActivityDAO* activityDAO;
        UserDAO* userDAO;
        ProjectDAO* projectDAO;
        ActivityExecutionDAO* activityExecutionDAO;

      protected:
        DAOFactory(int source);

      public:
        ~DAOFactory();
        const int getSource() const;
        static DAOFactory* getInstance(int source);
        ActivityDAO* getActivityDAO();
        UserDAO* getUserDAO();
        ProjectDAO* getProjectDAO();
        ActivityExecutionDAO* getActivityExecutionDAO();
    };
  }
}

#endif