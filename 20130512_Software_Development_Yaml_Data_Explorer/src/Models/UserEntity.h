#ifndef _MODELS_USER_ENTITY_H_
#define _MODELS_USER_ENTITY_H_

namespace Models {
  class UserEntity : public LegacyEntity{
    private:
      std::string name;
      bool isDeveloper;
      Time* entryAt;
      Time* departAt;
      LegacyEntityList* userActivitiesList;
      LegacyEntityList* userExecutionsList;
      LegacyEntityList* userProjectsList;
      DateTime* createdAt;
      DateTime* updatedAt;

    public:
      UserEntity();
      UserEntity(int const id, std::string const legacyId, std::string const name, bool const isDeveloper, Time* const entryAt, Time* const departAt, DateTime* const createdAt, DateTime* const updatedAt);
      ~UserEntity();

      const std::string getName() const;
      void setName(std::string const name);
      const bool getIsDeveloper() const;
      void setIsDeveloper(bool const isDeveloper);
      const Time* getEntryAt() const;
      void setEntryAt(Time* const entryAt);
      const Time* getDepartAt() const;
      void setDepartAt(Time* const departAt);
      const DateTime* getCreatedAt() const;
      void setCreatedAt(DateTime* const createdAt);
      const DateTime* getUpdatedAt() const;
      void setUpdatedAt(DateTime* const updatedAt);
      const LegacyEntityList* getActivitiesResponsible();
      const LegacyEntityList* getActivityExecutions();
      const LegacyEntityList* getProjects();
      const float getTotalUsedHours();
      const float getTotalEstimatedHours();
  };
}

#endif