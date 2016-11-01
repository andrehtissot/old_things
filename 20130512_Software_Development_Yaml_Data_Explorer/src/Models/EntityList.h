#ifndef _MODELS_ENTITY_LIST_H_
#define _MODELS_ENTITY_LIST_H_

namespace Models {
  class EntityList : public Utils::Lists::LinkedList<Entity> {
    public:
      EntityList();
      virtual ~EntityList();
      Entity* findById(int const id);
      void removeById(int const id);
  };
}

#endif