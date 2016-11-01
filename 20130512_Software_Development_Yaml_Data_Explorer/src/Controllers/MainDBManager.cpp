
Main::MainDBManager::MainDBManager(const int sourceParameter)
  : daoFactory(NULL), sourceParameter(sourceParameter) {}
Main::MainDBManager::~MainDBManager(){
  if(this->daoFactory != NULL)
    delete(this->daoFactory);
}
// const int MainDBManager::getSourceParameter() const{
//  return this->sourceParameter;
// }
// void MainDBManager::setSourceParameter(const int sourceParameter){
//  this->sourceParameter = sourceParameter;
// }
void Main::MainDBManager::setSourceParameter(const std::string sourceParameter){
  if(sourceParameter.compare("yaml") == 0)
    this->sourceParameter = Models::DAO::DAOFactory::PARTIALLY_YAML;
  else if(sourceParameter.compare("binary") == 0)
    this->sourceParameter = Models::DAO::DAOFactory::BINARY;
  else
    throw "ERROR: Only \"yaml\" and \"binary\" are valid parameters for source database.";
}
void Main::MainDBManager::loadDB(){
  switch(this->sourceParameter){
    case 0: //Default
      this->loadBinaryDBOnlyIfAvailable(); break;
    case Models::DAO::DAOFactory::PARTIALLY_YAML:
      this->loadYAMLDB(); break;
    case Models::DAO::DAOFactory::BINARY:
      this->loadBinaryDB(); break;
  }
}
const bool Main::MainDBManager::isBinarySourceAvailable() const{
  Directory* dir = new Directory("data/binary");
  bool is = dir->isDir() && !dir->isEmpty();
  delete(dir);
  return is;
}
const bool Main::MainDBManager::isYAMLSourceAvailable() const{
  Directory* dir = new Directory("data/yaml");
  bool is = dir->isDir() && !dir->isEmpty();
  delete(dir);
  return is;
}
void Main::MainDBManager::loadBinaryDBOnlyIfAvailable(){
  if(this->isBinarySourceAvailable()){
    this->loadBinaryDB();
  } else {
    this->loadYAMLDB();
  }
}
void Main::MainDBManager::loadBinaryDB(){
  if(this->isBinarySourceAvailable()){
    //TODO
  } else {
    throw "ERROR: Binary DB is not available.";
  }
}
void Main::MainDBManager::loadYAMLDB(){
  if(this->isYAMLSourceAvailable()) {
    this->daoFactory = DAOFactory::getInstance(Models::DAO::DAOFactory::PARTIALLY_YAML);
    Main* main = Main::getInstance();
    this->daoFactory->getActivityDAO()->loadAllToList(main->getActivityEntityList());
    this->daoFactory->getUserDAO()->loadAllToList(main->getUserEntityList());
    this->daoFactory->getProjectDAO()->loadAllToList(main->getProjectEntityList());
    this->daoFactory->getActivityExecutionDAO()->loadAllToList(main->getActivityExecutionEntityList());
  } else {
    throw "ERROR: YAML DB is not available.";
  }
}

