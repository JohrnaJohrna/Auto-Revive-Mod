#include "SFX.h"

using SFXA = EntityINS::EntityModule::SFX;

SFXA::SFX()
{

}

SFXA::SFX(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	SFX_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xB0 });
}

SFXA::~SFX()
{
	SFX_PTR = NULL;
}