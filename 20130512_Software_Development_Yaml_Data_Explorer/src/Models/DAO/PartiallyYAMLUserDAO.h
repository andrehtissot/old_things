#ifndef _MODELS_DAO_PARTIALLY_YAML_USER_DAO_H_
#define _MODELS_DAO_PARTIALLY_YAML_USER_DAO_H_
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.h"
#include "BinaryUserDAO.h"

namespace Models {
  namespace DAO {
    class PartiallyYAMLUserDAO : public BinaryUserDAO, public Models::DAO::PartiallyYAMLDAO::PartiallyYAMLDAOSource {
      public:
        PartiallyYAMLUserDAO();
        ~PartiallyYAMLUserDAO();
        void loadAllToList(EntityList* list);
    };
  }
}

#endif