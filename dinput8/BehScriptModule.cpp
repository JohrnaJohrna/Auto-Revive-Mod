#include "BehScriptModule.h"

using BehScriptA = EntityINS::EntityModule::BehScript;

BehScriptA::BehScript()
{

}

BehScriptA::BehScript(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	BehScript_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x10, 0x0 });
}

BehScriptA::~BehScript()
{
	BehScript_PTR = NULL;
}