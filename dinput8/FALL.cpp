#include "FALL.h"

using FALLA = EntityINS::EntityModule::FALL;

FALLA::FALL()
{

}

FALLA::FALL(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	FALL_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x70, 0x0 });
}

FALLA::~FALL()
{
	FALL_PTR = NULL;
}