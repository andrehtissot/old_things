#ifndef _MODELS_ENTITY_CPP_
#define _MODELS_ENTITY_CPP_

#include "Entity.h"
using namespace Models;

Entity::Entity(){};
Entity::Entity(const int id){
  this->id = id;
};
Entity::~Entity(){};
const int Entity::getId() const {
  return this->id;
}
void Entity::setId(const int id){
  this->id = id;
}
bool Entity::operator==(const Entity& entity) const{
	Entity* entityPointer = const_cast<Entity*>(&entity);
	return this->operator==(entityPointer);
}
bool Entity::operator==(Entity*& entity) const{
	if(this->id == 0) //It's incomparable. This entity seams to be lost.
		return false;
	return this->id == entity->id;
}
bool Entity::operator!=(const Entity& entity) const{
	return !(this->operator==(entity));
}
bool Entity::operator!=(Entity*& entity) const{
	return !(this->operator==(entity));
}
#endif