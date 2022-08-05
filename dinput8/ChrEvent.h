#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Event
{
private:
protected:
	uintptr_t Event_PTR;
public:
	Event();
	Event(EntityINS::EntityModule eModule);
	~Event();
};