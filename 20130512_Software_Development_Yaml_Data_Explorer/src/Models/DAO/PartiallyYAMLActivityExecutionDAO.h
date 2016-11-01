#ifndef _MODELS_DAO_PARTIALLY_YAML_ACTIVITY_EXECUTION_DAO_H_
#define _MODELS_DAO_PARTIALLY_YAML_ACTIVITY_EXECUTION_DAO_H_
#include "PartiallyYAMLDAO/PartiallyYAMLDAOSource.h"
#include "BinaryActivityExecutionDAO.h"
namespace Models {
  namespace DAO {
    class PartiallyYAMLActivityExecutionDAO : public BinaryActivityExecutionDAO, public Models::DAO::PartiallyYAMLDAO::PartiallyYAMLDAOSource {
      public:
        PartiallyYAMLActivityExecutionDAO();
        ~PartiallyYAMLActivityExecutionDAO();
      public:
        void loadAllToList(EntityList* list);
    };
  }
}

#endif