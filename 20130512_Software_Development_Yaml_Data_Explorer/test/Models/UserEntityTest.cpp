#include "../TestBase.cpp"
#include "../../src/Controllers/Main.cpp"
#include "../../src/Models/UserEntity.cpp"
using namespace Models;

class UserEntityTest : public TestBase {
	public:
		void testNew(){
			UserEntity* user1 = new UserEntity();
			reportIfDifferent(user1->getName(), "", __FUNCTION__, __LINE__);
			delete(user1);
			UserEntity* user2 = new UserEntity(10, "TEN", "NameTest", true, NULL, NULL, NULL, NULL);
			reportIfDifferent(user2->getName(), "NameTest", __FUNCTION__, __LINE__);
			reportIfDifferent(user2->getLegacyId(), "TEN", __FUNCTION__, __LINE__);
			reportIfDifferent(user2->getId(), 10, __FUNCTION__, __LINE__);
			delete(user2);
		}

		void testGetTotalUsedHours(){
			LegacyEntityList* users = Main::getInstance()->getUserEntityList();
			UserEntity* user = static_cast<UserEntity*>(users->findByLegacyId("1547efaabf881e837579449b08ff7f477b72ef5b"));
			std::cout << user->getTotalUsedHours() << std::endl;
			std::cout << user->getTotalEstimatedHours() << std::endl;
		}
};

int main(int argc, char* argv[]){
	UserEntityTest* userEntityTest = new UserEntityTest();
	Main::getInstance()->loadDB();
	userEntityTest->testNew();
	userEntityTest->testGetTotalUsedHours();
	delete(Main::getInstance());
	delete(userEntityTest);
}
