#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::HitStop
{
private:
protected:
	uintptr_t HitStop_PTR;
public:
	HitStop();
	HitStop(EntityINS::EntityModule eModule);
	~HitStop();
};