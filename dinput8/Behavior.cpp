#include "Behavior.h"

using BehaviorA = EntityINS::EntityModule::Behavior;

BehaviorA::Behavior()
{

}

BehaviorA::Behavior(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Behavior_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x28, 0x0 });
}

BehaviorA::~Behavior()
{
	Behavior_PTR = NULL;
}