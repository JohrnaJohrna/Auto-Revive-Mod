#include "HitStop.h"

using HitStopA = EntityINS::EntityModule::HitStop;

HitStopA::HitStop()
{

}

HitStopA::HitStop(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	HitStop_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x90, 0x0 });
}

HitStopA::~HitStop()
{
	HitStop_PTR = NULL;
}