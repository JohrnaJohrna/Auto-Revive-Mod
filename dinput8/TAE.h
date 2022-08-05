#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::TAE
{
private:
protected:
	uintptr_t TAE_PTR;
public:
	TAE();
	TAE(EntityINS::EntityModule eModule);
	~TAE();
};