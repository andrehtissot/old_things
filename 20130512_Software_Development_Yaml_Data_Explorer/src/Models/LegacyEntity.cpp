#ifndef _MODELS_LEGACY_ENTITY_CPP_
#define _MODELS_LEGACY_ENTITY_CPP_

#include "Entity.cpp"
#include "LegacyEntity.h"
using namespace Models;

LegacyEntity::LegacyEntity() : Entity() {
	this->legacyId = "";
};
LegacyEntity::LegacyEntity(int const id, const std::string legacyId)
	: Entity(id) {
  this->legacyId = legacyId;
};
LegacyEntity::~LegacyEntity(){};
const std::string LegacyEntity::getLegacyId() const {
  return this->legacyId;
}
void LegacyEntity::setLegacyId(const std::string legacyId){
  this->legacyId = legacyId;
}
bool LegacyEntity::operator==(const LegacyEntity& legacyEntity) const{
  LegacyEntity* legacyEntityPointer = const_cast<LegacyEntity*>(&legacyEntity);
  return this->operator==(legacyEntityPointer);
}
bool LegacyEntity::operator==(LegacyEntity*& legacyEntity) const{
	if(this->legacyId.compare("") != 0 && legacyEntity->legacyId.compare("") != 0)
		return this->legacyId.compare(legacyEntity->legacyId) == 0;
	//It's incomparable by legacyId, let's ask the parent implementation...
	Entity* legacyEntityAsEntity = dynamic_cast<Entity*>(legacyEntity);
	return ((Entity*) this)->operator==(legacyEntityAsEntity);
}
bool LegacyEntity::operator!=(const LegacyEntity& legacyEntity) const{
	return !(this->operator==(legacyEntity));
}
bool LegacyEntity::operator!=(LegacyEntity*& legacyEntity) const{
	return !(this->operator==(legacyEntity));
}
#endif