#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::AutoHoming
{
private:
protected:
	uintptr_t AutoHoming_PTR;
public:
	AutoHoming();
	AutoHoming(EntityINS::EntityModule eModule);
	~AutoHoming();
};