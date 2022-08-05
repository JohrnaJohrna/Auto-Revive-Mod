#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Position
{
private:
protected:
	uintptr_t Position_PTR;
public:
	Position();
	Position(EntityINS::EntityModule eModule);
	~Position();
};