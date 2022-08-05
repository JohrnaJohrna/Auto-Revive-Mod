#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::BehaviorData
{
private:
protected:
	uintptr_t BehaviorData_PTR;
public:
	BehaviorData();
	BehaviorData(EntityINS::EntityModule eModule);
	~BehaviorData();
};