#include "EntityModule.h"

using EntityModuleA = EntityINS::EntityModule;

EntityModuleA::EntityModule()
{
	
}

EntityModuleA::EntityModule(uintptr_t eIns)
{
	Memory_S memory;
	entityModule_PTR = memory.GetPointerAddress(eIns, { 0x190, 0x0 });
}
EntityModuleA::~EntityModule()
{
	entityModule_PTR = NULL;
}

//ChrData