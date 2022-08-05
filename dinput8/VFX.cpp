#include "VFX.h"

using VFXA = EntityINS::EntityModule::VFX;

VFXA::VFX()
{

}

VFXA::VFX(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	VFX_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xB8 });
}

VFXA::~VFX()
{
	VFX_PTR = NULL;
}