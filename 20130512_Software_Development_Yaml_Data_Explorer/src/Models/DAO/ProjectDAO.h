#ifndef _MODELS_DAO_PROJECT_DAO_H_
#define _MODELS_DAO_PROJECT_DAO_H_
#include "EntityDAO.h"
#include "../ProjectEntity.h"

namespace Models {
  namespace DAO {
    class ProjectDAO : public EntityDAO {
      protected:
        ProjectEntity tempProjectEntity;
        ProjectDAO(){};
      public:
        virtual ~ProjectDAO(){};
    };
  }
}

#endif