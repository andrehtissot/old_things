#ifndef _MODELS_DAO_BINARY_ACTIVITY_EXECUTION_DAO_CPP_
#define _MODELS_DAO_BINARY_ACTIVITY_EXECUTION_DAO_CPP_
#include <fstream>
#include "BinaryActivityExecutionDAO.h"
#include "BinaryDAO/BinaryDAOSource.cpp"
#include "../ActivityExecutionEntity.cpp"
using namespace Models::DAO;

BinaryActivityExecutionDAO::BinaryActivityExecutionDAO() : ActivityExecutionDAO(), BinaryDAOSource("activity_execution.rec"){};
BinaryActivityExecutionDAO::~BinaryActivityExecutionDAO(){};

void BinaryActivityExecutionDAO::saveAllFromList(EntityList* list){
	
}
void BinaryActivityExecutionDAO::loadAllToList(EntityList* list){

}
#endif