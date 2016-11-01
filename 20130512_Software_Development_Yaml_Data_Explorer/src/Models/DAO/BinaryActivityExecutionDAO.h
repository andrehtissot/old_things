#ifndef _MODELS_DAO_BINARY_ACTIVITY_EXECUTION_DAO_H_
#define _MODELS_DAO_BINARY_ACTIVITY_EXECUTION_DAO_H_
#include "BinaryDAO/BinaryDAOSource.h"
#include "ActivityExecutionDAO.h"


namespace Models {
  namespace DAO {
    class BinaryActivityExecutionDAO : public ActivityExecutionDAO, public Models::DAO::BinaryDAO::BinaryDAOSource {
      public:
        BinaryActivityExecutionDAO();
        virtual ~BinaryActivityExecutionDAO();
        virtual void saveAllFromList(EntityList* list);
        virtual void loadAllToList(EntityList* list);
    };
  }
}

#endif