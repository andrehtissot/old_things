#include "../../TestBase.cpp"
#include "../../../src/Models/DAO/BinaryActivityDAO.cpp"
using namespace Models::DAO;

class BinaryActivityDAOTest : public TestBase {
	public:
		void TestNew(){
			BinaryActivityDAO* binaryActivityDAO1 = new BinaryActivityDAO();
			delete(binaryActivityDAO1);
		}
};

int main(int argc, char* argv[]){
	BinaryActivityDAOTest* binaryActivityDAOTest = new BinaryActivityDAOTest();
	binaryActivityDAOTest->TestNew();
	delete(binaryActivityDAOTest);
}
