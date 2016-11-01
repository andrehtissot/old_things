#ifndef _MODELS_DAO_BINARY_PROJECT_DAO_CPP_
#define _MODELS_DAO_BINARY_PROJECT_DAO_CPP_
#include <fstream>
#include "BinaryProjectDAO.h"
#include "BinaryDAO/BinaryDAOSource.cpp"
#include "ProjectDAO.h"

using namespace Models::DAO;

BinaryProjectDAO::BinaryProjectDAO() : ProjectDAO(), BinaryDAOSource("user.rec"){};
BinaryProjectDAO::~BinaryProjectDAO(){};

void BinaryProjectDAO::saveAllFromList(EntityList* list){
	
}
void BinaryProjectDAO::loadAllToList(EntityList* list){

}

#endif