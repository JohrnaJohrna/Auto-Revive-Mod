#include "BehaviorSync.h"

using BehaviorSyncA = EntityINS::EntityModule::BehaviorSync;

BehaviorSyncA::BehaviorSync()
{

}

BehaviorSyncA::BehaviorSync(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	BehaviorSync_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x30, 0x0 });
}

BehaviorSyncA::~BehaviorSync()
{
	BehaviorSync_PTR = NULL;
}