#ifndef _MODELS_DAO_BINARY_USER_DAO_CPP_
#define _MODELS_DAO_BINARY_USER_DAO_CPP_
#include <fstream>
#include "BinaryDAO/BinaryDAOSource.cpp"
#include "BinaryUserDAO.h"
using namespace Models::DAO;
// #include <iostream>
// #include "../../Utils/DateAndTime/DateTime.cpp"
// #include "../../Utils/FileSystem/Directory.cpp"

BinaryUserDAO::BinaryUserDAO() : UserDAO(), BinaryDAOSource("user.rec"){};
BinaryUserDAO::~BinaryUserDAO(){};
// void BinaryUserDAO::insert(UserEntity* entity){
// 	UserEntity* user = static_cast<UserEntity*>(entity);
// 	Directory* dir = new Directory("data/binary");
// 	// | std::ios::app
// 	user->clearUserActivitiesList();
// 	user->clearUserExecutionsList();
// 	user->clearUserProjectsList();
// 	int nullVar = 0;
//     char tempChars[255];
//     DateTime tempDateTime = DateTime();
//     Time tempTime = Time();

// 	std::ofstream ofs(dir->absolutePath(this->BinaryDAOSource::getFileName()).c_str(), std::ios::binary);
// 	ofs.write((char *)user, sizeof(this->tempUserEntity));
// 	strcpy(tempChars, user->getName().c_str());
// 	ofs.write((char *)&tempChars, sizeof(tempChars));
// 	if(user->getCreatedAt() == NULL)
// 		ofs.write((char *)(new DateTime()), sizeof(tempDateTime));
// 	else
// 		ofs.write((char *)user->getCreatedAt(), sizeof(tempDateTime));
// 	if(user->getUpdatedAt() == NULL)
// 		ofs.write((char *)(new DateTime()), sizeof(tempDateTime));
// 	else
// 		ofs.write((char *)user->getUpdatedAt(), sizeof(tempDateTime));
// 	if(user->getEntryAt() == NULL)
// 		ofs.write((char *)(new Time()), sizeof(tempTime));
// 	else	
// 		ofs.write((char *)user->getEntryAt(), sizeof(tempTime));
// 	if(user->getDepartAt() == NULL)
// 		ofs.write((char *)(new Time()), sizeof(tempTime));
// 	else
// 		ofs.write((char *)user->getDepartAt(), sizeof(tempTime));
// 	// ofs.write(reinterpret_cast<const char *>(&nullVar), sizeof(tempTime));
// 	// entity->setId(this->insertNewRecordAndReturnId(entity));
// }
void BinaryUserDAO::saveAllFromList(EntityList* list){
	
}
void BinaryUserDAO::loadAllToList(EntityList* list){
 //    char tempChars[255];
 //    DateTime tempDateTime = DateTime();
 //    Time tempTime = Time();
	// UserEntity* user = new UserEntity();
	// Directory* dir = new Directory("data/binary");
	// std::ifstream ifs(dir->absolutePath(this->BinaryDAOSource::getFileName()).c_str(), std::ios::binary);
	// ifs.read((char *)user, sizeof(this->tempUserEntity));
	// ifs.read((char *)tempChars, sizeof(tempChars));
	// std::string userName = std::string(tempChars);
	// user->setName(userName);
	// DateTime *createDateTime = new DateTime();
	// ifs.read((char *)createDateTime, sizeof(tempDateTime));
	// user->setCreatedAt(createDateTime);
	// DateTime *updateDateTime = new DateTime();
	// ifs.read((char *)updateDateTime, sizeof(tempDateTime));
	// user->setUpdatedAt(updateDateTime);
	// Time* entryTime = new Time();
	// ifs.read((char *)entryTime, sizeof(tempTime));
	// user->setEntryAt(entryTime);
	// Time* departTime = new Time();
	// ifs.read((char *)departTime, sizeof(tempTime));
	// user->setDepartAt(departTime);
	// list->append(user);
}
#endif