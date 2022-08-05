#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::ActionRequest
{
private:
protected:
	uintptr_t ActionRequest_PTR;
public:
	ActionRequest();
	ActionRequest(EntityINS::EntityModule eModule);
	~ActionRequest();
};