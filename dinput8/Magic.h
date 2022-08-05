#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::Magic
{
private:
protected:
	uintptr_t Magic_PTR;
public:
	Magic();
	Magic(EntityINS::EntityModule eModule);
	~Magic();
};