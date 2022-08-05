#include "BehaviorData.h"

using StatusResistA = EntityINS::EntityModule::BehaviorData;

StatusResistA::BehaviorData()
{

}

StatusResistA::BehaviorData(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	BehaviorData_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xC0, 0x0 });
}

StatusResistA::~BehaviorData()
{
	BehaviorData_PTR = NULL;
}