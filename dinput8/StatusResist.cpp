#include "StatusResist.h"

using StatusResistA = EntityINS::EntityModule::StatusResist;

StatusResistA::StatusResist()
{

}

StatusResistA::StatusResist(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	StatusResist_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x20, 0x0 });
}

StatusResistA::~StatusResist()
{
	StatusResist_PTR = NULL;
}