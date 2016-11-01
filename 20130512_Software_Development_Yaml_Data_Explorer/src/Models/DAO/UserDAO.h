#ifndef _MODELS_DAO_USER_DAO_H_
#define _MODELS_DAO_USER_DAO_H_
#include "EntityDAO.h"
#include "../UserEntity.h"

namespace Models {
  namespace DAO {
    class UserDAO : public EntityDAO {
      protected:
        UserEntity tempUserEntity;
        UserDAO(){};
      public:
        virtual ~UserDAO(){};
    };
  }
}

#endif