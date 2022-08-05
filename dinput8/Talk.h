#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Talk
{
private:
protected:
	uintptr_t Talk_PTR;
public:
	Talk();
	Talk(EntityINS::EntityModule eModule);
	~Talk();
};