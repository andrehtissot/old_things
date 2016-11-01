#ifndef _MODELS_DAO_BINARY_ACTIVITY_DAO_H_
#define _MODELS_DAO_BINARY_ACTIVITY_DAO_H_
#include "BinaryDAO/BinaryDAOSource.h"
#include "ActivityDAO.h"

namespace Models {
  namespace DAO {
    class BinaryActivityDAO : public ActivityDAO, public Models::DAO::BinaryDAO::BinaryDAOSource {
      public:
        BinaryActivityDAO();
        virtual ~BinaryActivityDAO();
        virtual void saveAllFromList(EntityList* list);
        virtual void loadAllToList(EntityList* list);
    };
  }
}

#endif