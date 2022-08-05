#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::StatusResist
{
private:
protected:
	uintptr_t StatusResist_PTR;
public:
	StatusResist();
	StatusResist(EntityINS::EntityModule eModule);
	~StatusResist();
};