#include "../TestBase.cpp"
#include "../../src/Controllers/Main.cpp"
#include "../../src/Models/ActivityExecutionEntity.cpp"
using namespace Models;

class ActivityExecutionEntityTest : public TestBase {
	public:
		void TestNew(){
			ActivityExecutionEntity* ativityExecution2 = new ActivityExecutionEntity(10, "TEN", 7, 8, NULL, NULL);
			reportIfDifferent(ativityExecution2->getLegacyId(), "TEN", __FUNCTION__, __LINE__);
			reportIfDifferent(ativityExecution2->getId(), 10, __FUNCTION__, __LINE__);
			delete(ativityExecution2);
		}

		void TestGetActivity(){
			LegacyEntityList* executions = Main::getInstance()->getActivityExecutionEntityList();
			ActivityExecutionEntity* execution = static_cast<ActivityExecutionEntity*>(executions->get(0));
			ActivityEntity* activity = execution->getActivity();
			reportIfDifferent(execution->getActivityLegacyId(), activity->getLegacyId(), __FUNCTION__, __LINE__);
			reportIfNullC(activity->getActivityExecutions(), __FUNCTION__, __LINE__);
			if(NULL != activity->getActivityExecutions()){
				LegacyEntity* executionFound = activity->getActivityExecutions()->findByLegacyId(execution->getLegacyId());
				reportIfNull(executionFound, __FUNCTION__, __LINE__);
				if(NULL != executionFound)
					reportIfDifferent(executionFound->getLegacyId(), execution->getLegacyId(), __FUNCTION__, __LINE__);
			}
		}

		void TestGetExecuterUser(){
			LegacyEntityList* executions = Main::getInstance()->getActivityExecutionEntityList();
			ActivityExecutionEntity* execution = static_cast<ActivityExecutionEntity*>(executions->get(0));
			UserEntity* user = execution->getExecuterUser();
			reportIfDifferent(execution->getExecuterUserLegacyId(), user->getLegacyId(), __FUNCTION__, __LINE__);
			reportIfNullC(user->getActivityExecutions(), __FUNCTION__, __LINE__);
			if(NULL != user->getActivityExecutions()){
				LegacyEntity* executionFound = user->getActivityExecutions()->findByLegacyId(execution->getLegacyId());
				reportIfNull(executionFound, __FUNCTION__, __LINE__);
				if(NULL != executionFound)
					reportIfDifferent(executionFound->getLegacyId(), execution->getLegacyId(), __FUNCTION__, __LINE__);
			}
		}
};

int main(int argc, char* argv[]){
	ActivityExecutionEntityTest* ativityExecutionEntityTest = new ActivityExecutionEntityTest();
	Main::getInstance()->loadDB();
	ativityExecutionEntityTest->TestNew();
	ativityExecutionEntityTest->TestGetActivity();
	ativityExecutionEntityTest->TestGetExecuterUser();
	delete(Main::getInstance());
	delete(ativityExecutionEntityTest);
}
