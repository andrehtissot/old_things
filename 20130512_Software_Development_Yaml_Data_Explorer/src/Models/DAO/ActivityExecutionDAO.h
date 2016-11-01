#ifndef _MODELS_DAO_ACTIVITY_EXECUTION_DAO_H_
#define _MODELS_DAO_ACTIVITY_EXECUTION_DAO_H_
#include "EntityDAO.h"
#include "../ActivityExecutionEntity.h"

namespace Models {
  namespace DAO {
    class ActivityExecutionDAO : public EntityDAO {
      protected:
        ActivityExecutionEntity tempActivityExecutionEntity;
        ActivityExecutionDAO(){};
      public:
        virtual ~ActivityExecutionDAO(){};
    };
  }
}

#endif