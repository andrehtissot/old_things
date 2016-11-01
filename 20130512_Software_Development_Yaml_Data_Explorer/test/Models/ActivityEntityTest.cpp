#include "../TestBase.cpp"
#include "../../src/Controllers/Main.cpp"
#include "../../src/Models/ActivityEntity.cpp"
using namespace Models;

class ActivityEntityTest : public TestBase {
	public:
		void testNew(){
			ActivityEntity* activity1 = new ActivityEntity();
			reportIfDifferent(activity1->getTitle(), "", __FUNCTION__, __LINE__);
			delete(activity1);
			ActivityEntity* activity2 = new ActivityEntity(10, "TEN", 1, "TitleTest", ActivityEntity::STATUS_UNINITIATED,  ActivityEntity::TYPE_REQUIREMENT, "DescriptionTest", true, 0.0f, 2, 3, NULL, NULL);
			reportIfDifferent(activity2->getTitle(), "TitleTest", __FUNCTION__, __LINE__);
			reportIfDifferent(activity2->getLegacyId(), "TEN", __FUNCTION__, __LINE__);
			reportIfDifferent(activity2->getId(), 10, __FUNCTION__, __LINE__);
			delete(activity2);
		}

		void testGetResponsible(){
			LegacyEntityList* activities = Main::getInstance()->getActivityEntityList();
			ActivityEntity* activity = static_cast<ActivityEntity*>(activities->get(2));
			UserEntity* user = activity->getResponsible();
			reportIfDifferent(activity->getResponsibleLegacyId(), user->getLegacyId(), __FUNCTION__, __LINE__);
			reportIfNullC(user->getActivitiesResponsible(), __FUNCTION__, __LINE__);
			if(NULL != user->getActivitiesResponsible()){
				LegacyEntity* activityFound = user->getActivitiesResponsible()->findByLegacyId(activity->getLegacyId());
				reportIfNull(activityFound, __FUNCTION__, __LINE__);
				if(NULL != activityFound)
					reportIfDifferent(activityFound->getLegacyId(), activity->getLegacyId(), __FUNCTION__, __LINE__);
			}
		}

		void testGetProject(){
			LegacyEntityList* activities = Main::getInstance()->getActivityEntityList();
			ActivityEntity* activity = static_cast<ActivityEntity*>(activities->get(2));
			ProjectEntity* project = activity->getProject();
			reportIfDifferent(activity->getProjectLegacyId(), project->getLegacyId(), __FUNCTION__, __LINE__);
			reportIfNullC(project->getActivities(), __FUNCTION__, __LINE__);
			if(NULL != project->getActivities()){
				LegacyEntity* activityFound =  project->getActivities()->findByLegacyId(activity->getLegacyId());
				reportIfNull(activityFound, __FUNCTION__, __LINE__);
				if(NULL != activityFound)
					reportIfDifferent(activityFound->getLegacyId(), activity->getLegacyId(), __FUNCTION__, __LINE__);
			}
		}

		void testGetTotalUsedHours(){
			LegacyEntityList* activities = Main::getInstance()->getActivityEntityList();
			ActivityEntity* activity = static_cast<ActivityEntity*>(activities->get(2));
		}
};

int main(int argc, char* argv[]){
	ActivityEntityTest* activityEntityTest = new ActivityEntityTest();
	Main::getInstance()->loadDB();
	activityEntityTest->testNew();
	activityEntityTest->testGetResponsible();
	activityEntityTest->testGetProject();
	activityEntityTest->testGetTotalUsedHours();
	delete(Main::getInstance());
	delete(activityEntityTest);
}
