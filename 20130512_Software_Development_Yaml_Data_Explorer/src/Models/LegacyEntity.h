#ifndef _MODELS_LEGACY_ENTITY_H_
#define _MODELS_LEGACY_ENTITY_H_

namespace Models {
  class LegacyEntity : public Entity {
    private:
      std::string legacyId;
    protected:
      LegacyEntity();
      LegacyEntity(int const id, std::string legacyId);
    public:
      virtual ~LegacyEntity();
      const std::string getLegacyId() const;
      void setLegacyId(const std::string legacyId);
      bool operator==(const LegacyEntity& legacyEntity) const;
      bool operator==(LegacyEntity*& legacyEntity) const;
      bool operator!=(const LegacyEntity& legacyEntity) const;
      bool operator!=(LegacyEntity*& legacyEntity) const;
  };
}

#endif