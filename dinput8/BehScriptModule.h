#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::BehScript
{
private:
protected:
	uintptr_t BehScript_PTR;
public:
	BehScript();
	BehScript(EntityINS::EntityModule eModule);
	~BehScript();
};