#ifndef _MODELS_ENTITY_H_
#define _MODELS_ENTITY_H_

namespace Models {
  class Entity {
    private:
      int id;
    protected:
      Entity();
      Entity(int const id);
    public:
      virtual ~Entity();
      const int getId() const;
      void setId(int const id);
      bool operator==(const Entity& entity) const;
      bool operator==(Entity*& entity) const;
      bool operator!=(const Entity& entity) const;
      bool operator!=(Entity*& entity) const;
  };
}

#endif