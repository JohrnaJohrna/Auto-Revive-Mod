#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::VFX
{
private:
protected:
	uintptr_t VFX_PTR;
public:
	VFX();
	VFX(EntityINS::EntityModule eModule);
	~VFX();
};