#include "../../TestBase.cpp"
#include "../../../src/Models/DAO/PartiallyYAMLActivityDAO.cpp"
using namespace Models::DAO;

class PartiallyYAMLActivityDAOTest : public TestBase {
	public:
		void testNew(){
			PartiallyYAMLActivityDAO* partiallyYAMLActivityDAO1 = new PartiallyYAMLActivityDAO();
			delete(partiallyYAMLActivityDAO1);
		}
		void testLoadAllToList(){
			PartiallyYAMLActivityDAO* partiallyYAMLActivityDAO1 = new PartiallyYAMLActivityDAO();
			EntityList* list1 = new EntityList();
			partiallyYAMLActivityDAO1->loadAllToList(list1);
			std::cout << list1->count() << std::endl;
			list1->removeAll(true);
			delete(list1);
			delete(partiallyYAMLActivityDAO1);
		}
};

int main(int argc, char* argv[]){
	PartiallyYAMLActivityDAOTest* partiallyYAMLActivityDAOTest = new PartiallyYAMLActivityDAOTest();
	partiallyYAMLActivityDAOTest->testNew();
	partiallyYAMLActivityDAOTest->testLoadAllToList();
	delete(partiallyYAMLActivityDAOTest);
}
