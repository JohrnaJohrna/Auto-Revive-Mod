#include "ActionFlag.h"

using ActionFlagA = EntityINS::EntityModule::ActionFlag;

ActionFlagA::ActionFlag()
{

}

ActionFlagA::ActionFlag(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	actionFlag_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x8, 0x0 });
}

ActionFlagA::~ActionFlag()
{
	actionFlag_PTR = NULL;
}