#include "Event.h"

Signature EventManS = {
	"\x48\x8B\x0D\x00\x00\x00\x00\x32\xDB\x41\x8B\xF0\x48\x8B\xEA\x48\x85\xC9",
	"xxx????xxxxxxxxxxx",
	false
};

Signature EventFlagManS = {
	"\x48\x8B\x3D\x00\x00\x00\x00\x48\x85\xFF\x00\x00\x32\xC0\xE9",
	"xxx????xxx??xxx",
	false
};

Signature DbgEventManS = {
	"\x48\x8B\x0D\x00\x00\x00\x00\x48\x85\xC9\x00\x00\x83\xCF\x20",
	"xxx????xxx??xxx",
	false
};

Signature LuaEventManS = {
	"\x48\x8B\x05\x00\x00\x00\x00\x48\x85\xC0\x74\x00\x41\xBE\x01\x00\x00\x00\x44\x89\x75\x83",
	"xxx????xxxx?xxxxxxxxxx",
	false
};

Signature EventRegionManS = {
	"\x48\x8B\x0D\x00\x00\x00\x00\x8B\xD6\xE8\x00\x00\x00\x00\x48\x85\xC0\x0F\x84",
	"xxx????xxx????xxxxx",
	false
};

Signature EventStateS = {
	"\x48\x8B\x0D\x00\x00\x00\x00\x4C\x8D\x45\xC8\x48\x8D\x55\xB8\xE8",
	"xxx????xxxxxxxxx",
	false
};

GEvent::GEvent()
{
	Memory_S mem;

	EventMan = *(uintptr_t*)mem.GetSignature_BaseAddr(DbgEventManS, { 0x3, 0x7 });
	DbgEventMan = *(uintptr_t*)mem.GetSignature_BaseAddr(DbgEventManS, { 0x3, 0x7 });
	EventFlagMan = *(uintptr_t*)mem.GetSignature_BaseAddr(EventFlagManS, { 0x3, 0x7 });
	LuaEventMan = *(uintptr_t*)mem.GetSignature_BaseAddr(LuaEventManS, { 0x3, 0x7 });
}

GEvent::~GEvent()
{

}