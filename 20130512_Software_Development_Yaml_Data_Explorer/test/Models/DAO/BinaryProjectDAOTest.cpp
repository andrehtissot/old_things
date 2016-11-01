#include "../../TestBase.cpp"
#include "../../../src/Models/DAO/BinaryProjectDAO.cpp"
using namespace Models::DAO;

class BinaryProjectDAOTest : public TestBase {
	public:
		void TestNew(){
			BinaryProjectDAO* binaryProjectDAO = new BinaryProjectDAO();
			delete(binaryProjectDAO);
		}
};

int main(int argc, char* argv[]){
	BinaryProjectDAOTest* binaryProjectDAOTest = new BinaryProjectDAOTest();
	binaryProjectDAOTest->TestNew();
	delete(binaryProjectDAOTest);
}
