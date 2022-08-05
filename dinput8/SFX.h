#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::SFX
{
private:
protected:
	uintptr_t SFX_PTR;
public:
	SFX();
	SFX(EntityINS::EntityModule eModule);
	~SFX();
};