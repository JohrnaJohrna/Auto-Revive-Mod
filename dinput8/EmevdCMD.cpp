#include "EventCMD.h"

using EventCMDA = GEvent::EventCMD;

EventCMDA::EventCMD()
{

}

EventCMDA::EventCMD(uintptr_t EventFlagMan)
{
	_CEventFlagMan = EventFlagMan;
}

EventCMDA::~EventCMD()
{

}

void EventCMDA::SetEventFlag(int* EventFlagId, bool State)
{
	Memory_S mem;

	Signature SSetEventFlag = {
		"\x48\x89\x5C\x24\x10\x48\x89\x6C\x24\x18\x56\x57\x41\x56\x48\x83\xEC\x00\x8B\x3A",
		"xxxxxxxxxxxxxxxxx?xx",
		true
	};

	mem.Callx64Function(mem.GetSignature(SSetEventFlag), _CEventFlagMan, EventFlagId, State);
}
//2003
void EventCMDA::WarpPlayer(int AreaId, int BlockId, int RegionId, int IndexId, int* AreaEntityId)
{
	Memory_S mem;

	Signature SWarpPlayer = {
		"\x48\x83\xEC\x48\x48\xC7\x44\x24\x28\xFE\xFF\xFF\xFF\xE8\x00\x00\x00\x00\x48\x8D\x4C\x24\x20\x48\x89\x4C\x24\x30",
		"xxxxxxxxxxxxxx????xxxxxxxxxx",
		true
	};

	mem.Callx64Function(mem.GetSignature(SWarpPlayer), AreaId, BlockId, RegionId, IndexId, AreaEntityId);
}

void EventCMDA::TriggerAreaReload(bool isMyWorldCheck)
{
	Memory_S mem;

	Signature STriggerAreaReload = {
		"\x40\x55\x48\x8B\xEC\x48\x81\xEC\x00\x00\x00\x00\x48\xC7\x45\xA8\x00\x00\x00\x00\x48\x8B\x05\x00\x00\x00\x00\x48\x33\xC4\x48\x89\x45\x00\x84\xC9\x75",
		"xxxxxxxx????xxxx????xxx????xxxxxx?xxx",
		true
	};

	mem.Callx64Function(mem.GetSignature(STriggerAreaReload), isMyWorldCheck);
}
//2004

void EventCMDA::ReplenishSuppleItem(int SuppleItemType)
{
	Memory_S mem;

	Signature SReplenishSuppleItem = {
		"\x48\x89\x5C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x00\x48\x8B\x05\x00\x00\x00\x00\x8B\xF1\x48\x8B\x78\x08",
		"xxxx?xxxx?xxxx?xxx????xxxxxx",
		true
	};

	mem.Callx64Function(mem.GetSignature(SReplenishSuppleItem), SuppleItemType);
}