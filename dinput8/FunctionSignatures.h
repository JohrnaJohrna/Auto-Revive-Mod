#pragma once

#include "Memory_S.h"

static Signature SpEffectAdd = {
	"\x48\x8B\xC4\x48\x89\x58\x08\x48\x89\x70\x10\x57\x48\x81\xEC\xC0\x00\x00\x00\x0F\x28\x05\x06\x57\xDD\x02\x48\x8B\xF1\x0F\x28\x0D\x1C\x4B\xDD\x02\x48\x8D\x48\x88",
	"xxxxxxxxxxxxxxx????xxx????xxxxxx????xxxx",
	true
};

static Signature SpEffectErase = {
	"\x48\x83\xEC\x28\x8B\xC2\x48\x8B\x51\x08\x48\x85\xD2\x74\x0F\x90",
	"xxxxxxxxxxxxx??x",
	true
};