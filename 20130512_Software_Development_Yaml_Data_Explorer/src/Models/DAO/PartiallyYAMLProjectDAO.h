#ifndef _MODELS_DAO_PARTIALLY_YAML_PROJECT_DAO_H_
#define _MODELS_DAO_PARTIALLY_YAML_PROJECT_DAO_H_
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.h"
#include "BinaryProjectDAO.h"

namespace Models {
  namespace DAO {
    class PartiallyYAMLProjectDAO : public BinaryProjectDAO, public Models::DAO::PartiallyYAMLDAO::PartiallyYAMLDAOSource {
      public:
        PartiallyYAMLProjectDAO();
        ~PartiallyYAMLProjectDAO();
        void loadAllToList(EntityList* list);
    };
  }
}

#endif