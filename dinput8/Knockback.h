#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Knockback
{
private:
protected:
	uintptr_t Knockback_PTR;
public:
	Knockback();
	Knockback(EntityINS::EntityModule eModule);
	~Knockback();
};