#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Behavior
{
private:
protected:
	uintptr_t Behavior_PTR;
public:
	Behavior();
	Behavior(EntityINS::EntityModule eModule);
	~Behavior();
};