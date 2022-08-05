#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::BehaviorSync
{
private:
protected:
	uintptr_t BehaviorSync_PTR;
public:
	BehaviorSync();
	BehaviorSync(EntityINS::EntityModule eModule);
	~BehaviorSync();
};