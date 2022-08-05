#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::ActionFlag
{
private:
	int AnimCancel = 0x10;
	int iFrameTimer = 0x668;
	int SuperTaeFlag = 0x40;
protected:
	uintptr_t actionFlag_PTR;
public:
	ActionFlag();
	ActionFlag(EntityINS::EntityModule eModule);
	~ActionFlag();


};