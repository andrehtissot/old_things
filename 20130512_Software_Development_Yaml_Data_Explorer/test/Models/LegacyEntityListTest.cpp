#include "../TestBase.cpp"
#include "../../src/Models/LegacyEntityList.cpp"
using namespace Models;

class LegacyEntityListTest : public TestBase {
	public:
		class SubLegacyEntity : public LegacyEntity {};

		void testFindById(){
			LegacyEntityList* list1 = new LegacyEntityList();
			reportIfNotNull(list1->findById(0), __FUNCTION__, __LINE__);
			SubLegacyEntity* legacyEntity1 = new SubLegacyEntity();
			legacyEntity1->setId(1);
			SubLegacyEntity* legacyEntity2 = new SubLegacyEntity();
			legacyEntity2->setId(2);
			SubLegacyEntity* legacyEntity3 = new SubLegacyEntity();
			legacyEntity3->setId(3);
			list1->append(legacyEntity1);
			list1->append(NULL);
			list1->append(legacyEntity3);
			list1->append(legacyEntity2);
			reportIfDifferentObject(list1->findById(2), legacyEntity2, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(3), legacyEntity3, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(1), legacyEntity1, __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findById(0), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findById(-1), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findById(4), __FUNCTION__, __LINE__);
			delete(legacyEntity1);
			delete(legacyEntity2);
			delete(legacyEntity3);
			delete(list1);
		}
		void testRemoveById(){
			LegacyEntityList* list1 = new LegacyEntityList();
			list1->removeById(0);
			SubLegacyEntity* legacyEntity1 = new SubLegacyEntity();
			legacyEntity1->setId(1);
			SubLegacyEntity* legacyEntity2 = new SubLegacyEntity();
			legacyEntity2->setId(2);
			SubLegacyEntity* legacyEntity3 = new SubLegacyEntity();
			legacyEntity3->setId(3);
			list1->append(legacyEntity1);
			list1->append(NULL);
			list1->append(legacyEntity3);
			list1->append(legacyEntity2);
			list1->removeById(2);
			reportIfNotNull(list1->findById(2), __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(3), legacyEntity3, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(1), legacyEntity1, __FUNCTION__, __LINE__);
			list1->removeById(0);
			list1->removeById(-1);
			list1->removeById(4);
			delete(legacyEntity1);
			delete(legacyEntity2);
			delete(legacyEntity3);
			delete(list1);
		}
		void testFindByLegacyId(){
			LegacyEntityList* list1 = new LegacyEntityList();
			reportIfNotNull(list1->findByLegacyId(std::string("")), __FUNCTION__, __LINE__);
			SubLegacyEntity* legacyEntity1 = new SubLegacyEntity();
			legacyEntity1->setId(1);
			legacyEntity1->setLegacyId(std::string("ONE"));
			SubLegacyEntity* legacyEntity2 = new SubLegacyEntity();
			legacyEntity2->setId(2);
			legacyEntity2->setLegacyId("TWO");
			SubLegacyEntity* legacyEntity3 = new SubLegacyEntity();
			legacyEntity3->setId(3);
			legacyEntity3->setLegacyId(std::string("THREE"));
			list1->append(legacyEntity1);
			list1->append(NULL);
			list1->append(legacyEntity3);
			list1->append(legacyEntity2);
			reportIfDifferentObject(list1->findByLegacyId(std::string("TWO")), legacyEntity2, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findByLegacyId("THREE"), legacyEntity3, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findByLegacyId(std::string("ONE")), legacyEntity1, __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findByLegacyId(std::string("")), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findByLegacyId(std::string("NOTHING")), __FUNCTION__, __LINE__);
			delete(legacyEntity1);
			delete(legacyEntity2);
			delete(legacyEntity3);
			delete(list1);
		}
		void testRemoveByLegacyId(){
			LegacyEntityList* list1 = new LegacyEntityList();
			list1->removeByLegacyId("");
			list1->removeByLegacyId("NOTHING");
			SubLegacyEntity* legacyEntity1 = new SubLegacyEntity();
			legacyEntity1->setId(1);
			legacyEntity1->setLegacyId(std::string("ONE"));
			SubLegacyEntity* legacyEntity2 = new SubLegacyEntity();
			legacyEntity2->setId(2);
			legacyEntity2->setLegacyId("TWO");
			SubLegacyEntity* legacyEntity3 = new SubLegacyEntity();
			legacyEntity3->setId(3);
			legacyEntity3->setLegacyId(std::string("THREE"));
			list1->append(legacyEntity1);
			list1->append(NULL);
			list1->append(legacyEntity3);
			list1->append(legacyEntity2);
			list1->removeByLegacyId(std::string("TWO"));
			reportIfNotNull(list1->findById(2), __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(3), legacyEntity3, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(1), legacyEntity1, __FUNCTION__, __LINE__);
			list1->removeByLegacyId("");
			list1->removeByLegacyId("NOTHING");
			list1->removeByLegacyId("THREE");
			reportIfNotNull(list1->findById(2), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findById(3), __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(1), legacyEntity1, __FUNCTION__, __LINE__);
			list1->removeByLegacyId("");
			list1->removeByLegacyId("NOTHING");
			delete(legacyEntity1);
			delete(legacyEntity2);
			delete(legacyEntity3);
			delete(list1);
		}
};

int main(int argc, char* argv[]){
	LegacyEntityListTest* legacyEntityListTest = new LegacyEntityListTest();
	legacyEntityListTest->testFindById();
	legacyEntityListTest->testRemoveById();
	legacyEntityListTest->testFindByLegacyId();
	legacyEntityListTest->testRemoveByLegacyId();
	delete(legacyEntityListTest);
}
