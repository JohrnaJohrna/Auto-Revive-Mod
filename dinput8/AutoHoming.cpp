#include "AutoHoming.h"

using AutoHomingA = EntityINS::EntityModule::AutoHoming;

AutoHomingA::AutoHoming()
{

}

AutoHomingA::AutoHoming(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	AutoHoming_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x100, 0x0 });
}

AutoHomingA::~AutoHoming()
{
	AutoHoming_PTR = NULL;
}