#include "GrassHit.h"

using GrassHitA = EntityINS::EntityModule::GrassHit;

GrassHitA::GrassHit()
{

}

GrassHitA::GrassHit(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	GrassHit_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x118, 0x0 });
}

GrassHitA::~GrassHit()
{
	GrassHit_PTR = NULL;
}