#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::AI
{
private:
protected:
	uintptr_t AI_PTR;
public:
	AI();
	AI(EntityINS::EntityModule eModule);
	~AI();
};