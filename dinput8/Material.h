#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Material
{
private:
protected:
	uintptr_t Material_PTR;
public:
	Material();
	Material(EntityINS::EntityModule eModule);
	~Material();
};