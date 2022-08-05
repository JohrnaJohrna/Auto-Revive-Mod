#include "WheelRotation.h"

using WheelRotationA = EntityINS::EntityModule::WheelRotation;

WheelRotationA::WheelRotation()
{

}

WheelRotationA::WheelRotation(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	WheelRotation_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x120 });
}

WheelRotationA::~WheelRotation()
{
	WheelRotation_PTR = NULL;
}