#include "Controllers/Main.cpp"

int main(int argc, char* argv[]){
  bool waitSource = false;
  for(int i = 1; i < argc; i++){
    if(waitSource){
      try {
        Main::getInstance()->setDBSourceParameter(std::string(argv[i]));
      } catch(char const* message) {
        std::cout << message << std::endl;
        return(-1);
      }
      waitSource = false;
    } else if(std::strcmp(argv[i],"--source") == 0 || std::strcmp(argv[i],"-s") == 0){
      waitSource = true;
    } else {
      break;
    }
  }
  if(waitSource) {
    std::cout << "ERROR: The parameter --source (-s) must be \"yaml\" or \"binary\"." << std::endl;
    return(-1);
  }
  Main::getInstance()->init();
  delete(Main::getInstance());
}