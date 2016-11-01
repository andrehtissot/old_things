#ifndef _MODELS_DAO_BINARY_PROJECT_DAO_H_
#define _MODELS_DAO_BINARY_PROJECT_DAO_H_
#include "BinaryDAO/BinaryDAOSource.h"
#include "ProjectDAO.h"

namespace Models {
  namespace DAO {
    class BinaryProjectDAO : public ProjectDAO, public Models::DAO::BinaryDAO::BinaryDAOSource {
      public:
        BinaryProjectDAO();
        virtual ~BinaryProjectDAO();
        virtual void saveAllFromList(EntityList* list);
        virtual void loadAllToList(EntityList* list);
    };
  }
}

#endif