#ifndef _MODELS_DAO_BINARY_ACTIVITY_DAO_CPP_
#define _MODELS_DAO_BINARY_ACTIVITY_DAO_CPP_
#include "BinaryActivityDAO.h"
#include "BinaryDAO/BinaryDAOSource.cpp"
#include "ActivityDAO.h"

using namespace Models::DAO;

BinaryActivityDAO::BinaryActivityDAO() : ActivityDAO(), BinaryDAOSource("activity.rec"){};
BinaryActivityDAO::~BinaryActivityDAO(){};

void BinaryActivityDAO::saveAllFromList(EntityList* list){
	
}
void BinaryActivityDAO::loadAllToList(EntityList* list){

}

#endif