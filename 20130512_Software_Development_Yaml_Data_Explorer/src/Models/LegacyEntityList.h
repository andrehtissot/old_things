#ifndef _MODELS_LEGACY_ENTITY_LIST_H_
#define _MODELS_LEGACY_ENTITY_LIST_H_

namespace Models {
  class LegacyEntityList : public EntityList {
    public:
      LegacyEntityList();
      ~LegacyEntityList();
      LegacyEntity* findByLegacyId(std::string const legacyId) const;
      void removeByLegacyId(std::string const legacyId);
  };
}

#endif