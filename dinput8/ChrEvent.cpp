#include "ChrEvent.h"

using EventA = EntityINS::EntityModule::Event;

EventA::Event()
{

}

EventA::Event(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Event_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x58, 0x0 });
}

EventA::~Event()
{
	Event_PTR = NULL;
}