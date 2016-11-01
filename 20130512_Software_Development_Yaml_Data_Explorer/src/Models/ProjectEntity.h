#ifndef _MODELS_PROJECT_ENTITY_H_
#define _MODELS_PROJECT_ENTITY_H_

namespace Models {
  class ProjectEntity : public LegacyEntity{
    private:
      std::string name;
      bool isActive;
      LegacyEntityList* projectActivitiesList;
      DateTime* createdAt;
      DateTime* updatedAt;

    public:
      ProjectEntity();
      ProjectEntity(int const id, std::string const legacyId, std::string const name, bool const isActive, DateTime* const createdAt, DateTime* const updatedAt);
      ~ProjectEntity();

      const std::string getName() const;
      void setName(std::string const name);
      const bool getIsActive() const;
      void setIsActive(bool const isActive);
      const DateTime* getCreatedAt() const;
      void setCreatedAt(DateTime* const createdAt);
      const DateTime* getUpdatedAt() const;
      void setUpdatedAt(DateTime* const updatedAt);
      const LegacyEntityList* getActivities();
      const float getTotalUsedHours();
      const float getTotalEstimatedHours();
  };
}

#endif