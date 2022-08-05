#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::BoneMove
{
private:
protected:
	uintptr_t BoneMove_PTR;
public:
	BoneMove();
	BoneMove(EntityINS::EntityModule eModule);
	~BoneMove();
};