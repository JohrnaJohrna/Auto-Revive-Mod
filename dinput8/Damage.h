#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Damage
{
private:
protected:
	uintptr_t Damage_PTR;
public:
	Damage();
	Damage(EntityINS::EntityModule eModule);
	~Damage();
};