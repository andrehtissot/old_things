#ifndef _MODELS_DAO_ENTITY_DAO_H_
#define _MODELS_DAO_ENTITY_DAO_H_

namespace Models {
  namespace DAO {
    class EntityDAO {
      protected:
        EntityDAO(){}
      public:
        virtual ~EntityDAO(){}
      public:
        virtual void saveAllFromList(EntityList* list) = 0;
        virtual void loadAllToList(EntityList* list) = 0;
    };
  }
}

#endif