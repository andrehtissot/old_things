#include "../../TestBase.cpp"
#include "../../../src/Models/DAO/PartiallyYAMLActivityExecutionDAO.cpp"
using namespace Models::DAO;

class PartiallyYAMLActivityExecutionDAOTest : public TestBase {
	public:
		void testNew(){
			PartiallyYAMLActivityExecutionDAO* partiallyYAMLActivityExecutionDAO = new PartiallyYAMLActivityExecutionDAO();
			delete(partiallyYAMLActivityExecutionDAO);
		}
		void testLoadAllToList(){
			PartiallyYAMLActivityExecutionDAO* partiallyYAMLActivityExecutionDAO = new PartiallyYAMLActivityExecutionDAO();
			EntityList* list1 = new EntityList();
			partiallyYAMLActivityExecutionDAO->loadAllToList(list1);
			std::cout << list1->count() << std::endl;

			//Free Memory
			Utils::Lists::Iterator<Entity>* iterator = list1->createIterator();
			ActivityExecutionEntity* currentItem = static_cast<ActivityExecutionEntity*>(iterator->getCurrentItem());
			while(currentItem != NULL || iterator->hasNext()) {
				if(currentItem != NULL)
					delete(currentItem);
				iterator->next();
				currentItem = static_cast<ActivityExecutionEntity*>(iterator->getCurrentItem());
			}
			delete(iterator);
			list1->removeAll();
			delete(list1);
			delete(partiallyYAMLActivityExecutionDAO);
		}
};

int main(int argc, char* argv[]){
	PartiallyYAMLActivityExecutionDAOTest* partiallyYAMLActivityExecutionDAOTest = new PartiallyYAMLActivityExecutionDAOTest();
	partiallyYAMLActivityExecutionDAOTest->testNew();
	partiallyYAMLActivityExecutionDAOTest->testLoadAllToList();
	delete(partiallyYAMLActivityExecutionDAOTest);
}
