#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Toughness
{
private:
protected:
	uintptr_t Toughness_PTR;
public:
	Toughness();
	Toughness(EntityINS::EntityModule eModule);
	~Toughness();
};