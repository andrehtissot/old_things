#include "../../TestBase.cpp"
#include "../../../src/Models/DAO/PartiallyYAMLProjectDAO.cpp"
using namespace Models::DAO;

class PartiallyYAMLProjectDAOTest : public TestBase {
	public:
		void testNew(){
			PartiallyYAMLProjectDAO* partiallyYAMLProjectDAO1 = new PartiallyYAMLProjectDAO();
			delete(partiallyYAMLProjectDAO1);
		}
		void testLoadAllToList(){
			PartiallyYAMLProjectDAO* partiallyYAMLProjectDAO1 = new PartiallyYAMLProjectDAO();
			EntityList* list1 = new EntityList();
			partiallyYAMLProjectDAO1->loadAllToList(list1);
			std::cout << list1->count() << std::endl;

			//Free Memory
			Utils::Lists::Iterator<Entity>* iterator = list1->createIterator();
			Entity* currentItem = iterator->getCurrentItem();
			while(currentItem != NULL || iterator->hasNext()) {
				if(currentItem != NULL){
					ProjectEntity* currentProject = static_cast<ProjectEntity*>(currentItem);
					delete(currentProject);
				}
				iterator->next();
				currentItem = iterator->getCurrentItem();
			}
			delete(iterator);
			delete(list1);
			delete(partiallyYAMLProjectDAO1);
		}
};

int main(int argc, char* argv[]){
	PartiallyYAMLProjectDAOTest* partiallyYAMLProjectDAOTest = new PartiallyYAMLProjectDAOTest();
	partiallyYAMLProjectDAOTest->testNew();
	partiallyYAMLProjectDAOTest->testLoadAllToList();
	delete(partiallyYAMLProjectDAOTest);
}
