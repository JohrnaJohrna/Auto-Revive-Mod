#include "ModelParamModifier.h"

using ModelParamModifierA = EntityINS::EntityModule::ModelParamModifier;

ModelParamModifierA::ModelParamModifier()
{

}

ModelParamModifierA::ModelParamModifier(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	ModelParamModifier_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xD0 });
}

ModelParamModifierA::~ModelParamModifier()
{
	ModelParamModifier_PTR = NULL;
}