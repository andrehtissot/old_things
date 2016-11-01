#include "../TestBase.cpp"
#include "../../src/Models/EntityList.cpp"

using namespace Models;

class EntityListTest : public TestBase {
	public:
		class SubEntity : public Entity {};

		void testFindById(){
			EntityList* list1 = new EntityList();
			reportIfNotNull(list1->findById(0), __FUNCTION__, __LINE__);
			SubEntity* entity1 = new SubEntity();
			entity1->setId(1);
			SubEntity* entity2 = new SubEntity();
			entity2->setId(2);
			SubEntity* entity3 = new SubEntity();
			entity3->setId(3);
			list1->append(entity1);
			list1->append(NULL);
			list1->append(entity3);
			list1->append(entity2);
			reportIfDifferentObject(list1->findById(2), entity2, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(3), entity3, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(1), entity1, __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findById(0), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findById(-1), __FUNCTION__, __LINE__);
			reportIfNotNull(list1->findById(4), __FUNCTION__, __LINE__);
			delete(entity1);
			delete(entity2);
			delete(entity3);
			delete(list1);
		}
		void testRemoveById(){
			EntityList* list1 = new EntityList();
			list1->removeById(0);
			SubEntity* entity1 = new SubEntity();
			entity1->setId(1);
			SubEntity* entity2 = new SubEntity();
			entity2->setId(2);
			SubEntity* entity3 = new SubEntity();
			entity3->setId(3);
			list1->append(entity1);
			list1->append(NULL);
			list1->append(entity3);
			list1->append(entity2);
			list1->removeById(2);
			reportIfNotNull(list1->findById(2), __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(3), entity3, __FUNCTION__, __LINE__);
			reportIfDifferentObject(list1->findById(1), entity1, __FUNCTION__, __LINE__);
			list1->removeById(0);
			list1->removeById(-1);
			list1->removeById(4);
			delete(entity1);
			delete(entity2);
			delete(entity3);
			delete(list1);
		}
};

int main(int argc, char* argv[]){
	EntityListTest* entityListTest = new EntityListTest();
	entityListTest->testFindById();
	entityListTest->testRemoveById();
	delete(entityListTest);
}
