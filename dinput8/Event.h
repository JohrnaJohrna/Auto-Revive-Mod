#pragma once

#include "Memory_S.h"

class GEvent {
private:
	uintptr_t EventMan;
	uintptr_t DbgEventMan;
	uintptr_t EventFlagMan;
	uintptr_t LuaEventMan;
public:
	GEvent();
	~GEvent();

	class EventCMD;

	EventCMD* _EventCMD;
};