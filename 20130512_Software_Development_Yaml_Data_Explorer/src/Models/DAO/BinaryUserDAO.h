#ifndef _MODELS_DAO_BINARY_USER_DAO_H_
#define _MODELS_DAO_BINARY_USER_DAO_H_
#include "BinaryDAO/BinaryDAOSource.h"
#include "UserDAO.h"

namespace Models {
  namespace DAO {
    class BinaryUserDAO : public UserDAO, public Models::DAO::BinaryDAO::BinaryDAOSource {
      public:
        BinaryUserDAO();
        virtual ~BinaryUserDAO();
        virtual void saveAllFromList(EntityList* list);
        virtual void loadAllToList(EntityList* list);
    };
  }
}

#endif