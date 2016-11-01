#ifndef _MODELS_DAO_PARTIALLY_YAML_ACTIVITY_DAO_H_
#define _MODELS_DAO_PARTIALLY_YAML_ACTIVITY_DAO_H_
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.h"
#include "BinaryActivityDAO.h"

namespace Models {
  namespace DAO {
    class PartiallyYAMLActivityDAO : public BinaryActivityDAO, public Models::DAO::PartiallyYAMLDAO::PartiallyYAMLDAOSource {
      public:
        PartiallyYAMLActivityDAO();
        ~PartiallyYAMLActivityDAO();
        void loadAllToList(EntityList* list);
    };
  }
}

#endif