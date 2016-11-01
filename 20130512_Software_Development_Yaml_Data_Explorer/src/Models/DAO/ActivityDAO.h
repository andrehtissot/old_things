#ifndef _MODELS_DAO_ACTIVITY_DAO_H_
#define _MODELS_DAO_ACTIVITY_DAO_H_
#include "EntityDAO.h"
#include "../ActivityEntity.h"

namespace Models {
  namespace DAO {
    class ActivityDAO : public EntityDAO {
      protected:
        ActivityEntity tempActivityEntity;
        ActivityDAO(){};
      public:
        virtual ~ActivityDAO(){};
    };
  }
}

#endif