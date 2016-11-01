#include "../../TestBase.cpp"
#include "../../../src/Utils/FileSystem/Directory.cpp"
using namespace Utils::FileSystem;

class DirectoryTest : public TestBase {
	public:
		void testFindFilePaths(){
			Directory* dir = new Directory("data/yaml");
			std::vector<std::string>* files = dir->findFilePaths("card.yml");
			int size = files->size();
			for(int i = 0; i < size; i++){
				std::cout << files->at(i) << std::endl;
			}
			delete(files);
			delete(dir);
		}
		void testAbsolutePathAsCharPointer(){
			Directory* dir = new Directory("data/yaml");
			// std::cout << dir->absolutePathAsCharPointer("2", "teste") << std::endl;
			// std::cout << dir->absolutePathAsCharPointer("2") << std::endl;
			// std::cout << dir->absolutePathAsCharPointer("2", "novo") << std::endl;
			// std::cout << dir->absolutePathAsCharPointer("2") << std::endl;
			delete(dir);
		}
		void testIsDir(){
			Directory* dir = new Directory("data/yaml");
			reportIfFalse(dir->isDir(), __FUNCTION__, __LINE__);
			delete(dir);
		}
};

int main(int argc, char* argv[]){
	DirectoryTest* directoryTest = new DirectoryTest();
	directoryTest->testFindFilePaths();
	directoryTest->testAbsolutePathAsCharPointer();
	directoryTest->testIsDir();
	delete(directoryTest);
}
