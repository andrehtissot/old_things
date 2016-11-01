#include "../TestBase.cpp"
#include "../../src/Controllers/Main.cpp"
#include "../../src/Models/ProjectEntity.cpp"
using namespace Models;

class ProjectEntityTest : public TestBase {
	public:
		void TestNew(){
			ProjectEntity* project1 = new ProjectEntity();
			reportIfDifferent(project1->getName(), "", __FUNCTION__, __LINE__);
			delete(project1);
			ProjectEntity* project2 = new ProjectEntity(10, "TEN", "NameTest", true, NULL, NULL);
			reportIfDifferent(project2->getName(), "NameTest", __FUNCTION__, __LINE__);
			reportIfDifferent(project2->getLegacyId(), "TEN", __FUNCTION__, __LINE__);
			reportIfDifferent(project2->getId(), 10, __FUNCTION__, __LINE__);
			delete(project2);
		}

		void testGetTotalUsedHours(){
			LegacyEntityList* projects = Main::getInstance()->getProjectEntityList();
			ProjectEntity* project = static_cast<ProjectEntity*>(projects->findByLegacyId("76903e72697cdc63a66e930f1ae12d3b6864d312"));
			std::cout << project->getTotalUsedHours() << std::endl;
			std::cout << project->getTotalEstimatedHours() << std::endl;
		}
};

int main(int argc, char* argv[]){
	ProjectEntityTest* projectEntityTest = new ProjectEntityTest();
	Main::getInstance()->loadDB();
	projectEntityTest->TestNew();
	projectEntityTest->testGetTotalUsedHours();
	delete(Main::getInstance());
	delete(projectEntityTest);
}
