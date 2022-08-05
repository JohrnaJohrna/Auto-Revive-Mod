#include "ActionRequest.h"

using ActionRequestA = EntityINS::EntityModule::ActionRequest;

ActionRequestA::ActionRequest()
{

}

ActionRequestA::ActionRequest(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	ActionRequest_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x80, 0x0 });
}

ActionRequestA::~ActionRequest()
{
	ActionRequest_PTR = NULL;
}