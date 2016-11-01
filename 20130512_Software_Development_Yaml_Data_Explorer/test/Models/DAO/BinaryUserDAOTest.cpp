#include "../../TestBase.cpp"
#include "../../../src/Models/DAO/BinaryUserDAO.cpp"
using namespace Models::DAO;

class BinaryUserDAOTest : public TestBase {
	public:
		void TestNew(){
			BinaryUserDAO* binaryUserDAO = new BinaryUserDAO();
			delete(binaryUserDAO);
		}
};

int main(int argc, char* argv[]){
	BinaryUserDAOTest* binaryUserDAOTest = new BinaryUserDAOTest();
	binaryUserDAOTest->TestNew();
	delete(binaryUserDAOTest);
}
