#include "../../TestBase.cpp"
#include "../../../src/Models/DAO/BinaryActivityExecutionDAO.cpp"
using namespace Models::DAO;

class BinaryActivityExecutionDAOTest : public TestBase {
	public:
		void TestNew(){
			BinaryActivityExecutionDAO* binaryActivityExecutionDAO1 = new BinaryActivityExecutionDAO();
			delete(binaryActivityExecutionDAO1);
		}
};

int main(int argc, char* argv[]){
	BinaryActivityExecutionDAOTest* binaryActivityExecutionDAOTest = new BinaryActivityExecutionDAOTest();
	binaryActivityExecutionDAOTest->TestNew();
	delete(binaryActivityExecutionDAOTest);
}
