#ifndef _MODELS_ACTIVITY_EXECUTION_ENTITY_H_
#define _MODELS_ACTIVITY_EXECUTION_ENTITY_H_

namespace Models {
  class ActivityEntity;
  class UserEntity;
  class ActivityExecutionEntity : public LegacyEntity{
    private:
      int executerUserId; //For lazy load
      std::string executerUserLegacyId; //For lazy load
      UserEntity* executerUser;
      int activityId; //For lazy load
      std::string activityLegacyId; //For lazy load
      ActivityEntity* activity;
      DateTime* startedAt;
      DateTime* endedAt;

    public:
      ActivityExecutionEntity();
      ActivityExecutionEntity(int const id, std::string const legacyId, int const executerUserId, int const activityId, DateTime* const startedAt, DateTime* const endedAt);
      ActivityExecutionEntity(int const id, std::string const legacyId, std::string const executerUserLegacyId, std::string const activityLegacyId, DateTime* const startedAt, DateTime* const endedAt);
      ~ActivityExecutionEntity();

      const DateTime* getStartedAt() const;
      void setStartedAt(DateTime* const startedAt);
      const DateTime* getEndedAt() const;
      void setEndedAt(DateTime* const endedAt);
      UserEntity* getExecuterUser();
      void setExecuterUser(UserEntity* const executerUser);
      ActivityEntity* getActivity() ;
      void setActivity(ActivityEntity* const activity);
      void setExecuterUserId(int const executerUserId);
      const int getExecuterUserId() const;
      void setExecuterUserLegacyId(std::string const executerUserLegacyId);
      const std::string getExecuterUserLegacyId() const;
      void setActivityId(int const activityId);
      const int getActivityId() const;
      void setActivityLegacyId(std::string const activityLegacyId);
      const std::string getActivityLegacyId() const;
      const float getSpentHours() const;
  };
}

#endif