#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::ModelParamModifier
{
private:
protected:
	uintptr_t ModelParamModifier_PTR;
public:
	ModelParamModifier();
	ModelParamModifier(EntityINS::EntityModule eModule);
	~ModelParamModifier();
};