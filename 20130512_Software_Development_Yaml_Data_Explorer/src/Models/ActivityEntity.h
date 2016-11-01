#ifndef _MODELS_ACTIVITY_ENTITY_H_
#define _MODELS_ACTIVITY_ENTITY_H_

namespace Models {
  class ActivityEntity : public LegacyEntity{
    private:
      int priority;
      std::string title;
      int status;
      int type;
      std::string description;
      bool isDevelopment;
      float effortEstimate;
      int projectId; //For lazy load
      std::string projectLegacyId; //For lazy load
      ProjectEntity* project;
      int responsibleId; //For lazy load
      std::string responsibleLegacyId; //For lazy load
      UserEntity* responsible;
      LegacyEntityList* executionsList;
      DateTime* createdAt;
      DateTime* updatedAt;

    public:
      ActivityEntity();
      ActivityEntity(int const id, std::string const legacyId, int const priority, std::string const title, int const status, int const type, std::string const description, bool const isDevelopment, float const effortEstimate, int const projectId, int const responsibleId, DateTime* const createdAt, DateTime* const updatedAt);
      ActivityEntity(int const id, std::string const legacyId, int const priority, std::string const title, int const status, int const type, std::string const description, bool const isDevelopment, float const effortEstimate, std::string const projectLegacyId, std::string const responsibleLegacyId, DateTime* const createdAt, DateTime* const updatedAt);
      ~ActivityEntity();

      static const int TYPE_REQUIREMENT = 1;
      static const int TYPE_TEAM_TASK = 2;
      static const int TYPE_DETAIL = 3;
      static const int TYPE_SOFTWARE_BUG = 4;
      static const int TYPE_ANALYSIS_BUG = 5;
      static const int TYPE_PENDENCY = 6;
      static const int STATUS_UNINITIATED = 1;
      static const int STATUS_ONGOING = 2;
      static const int STATUS_FINALIZED = 3;

      const int getPriority() const;
      void setPriority(int const priority);
      const std::string getTitle() const;
      void setTitle(std::string const title);
      const int getStatus() const;
      void setStatus(int const status);
      const int getType() const;
      void setType(int const type);
      const std::string getDescription() const;
      void setDescription(std::string const description);
      const bool getIsDevelopment() const;
      void setIsDevelopment(bool const isDevelopment);
      const float getEffortEstimate() const;
      void setEffortEstimate(float const effortEstimate);
      const DateTime* getCreatedAt() const;
      void setCreatedAt(DateTime* const createdAt);
      const DateTime* getUpdatedAt() const;
      void setUpdatedAt(DateTime* const updatedAt);
      ProjectEntity* getProject();
      void setProject(ProjectEntity* const project);
      UserEntity* getResponsible();
      void setResponsible(UserEntity* const responsible);
      const int getProjectId() const;
      void setProjectId(int const projectId);
      const std::string getProjectLegacyId() const;
      void setProjectLegacyId(std::string const projectLegacyId);
      const int getResponsibleId() const;
      void setResponsibleId(int const responsibleId);
      const std::string getResponsibleLegacyId() const;
      void setResponsibleLegacyId(std::string const responsibleLegacyId);
      const LegacyEntityList* getActivityExecutions();
      const float getTotalUsedHours();
      const float getTotalEstimatedHours();
  };
}

#endif