#pragma once

#include "Event.h"

enum class SoundType : unsigned char {
	Type0 = 0,

};

class GEvent::EventCMD {
private:
	uintptr_t _CEventFlagMan;
public:
	EventCMD();
	EventCMD(uintptr_t EventFlagMan);
	~EventCMD();

	void SetEventFlag(int* EventFlagID, bool State);
	//2003
	void WarpPlayer(int AreaId, int BlockId, int RegionId, int IndexId, int* AreaEntityId);
	void TriggerAreaReload(bool isMyWorldCheck);
	//2004
	void ReplenishSuppleItem(int SuppleItemType);
	//2006
	void SpawnOneshotVFX(int* EntityId, int SfxId, int dummyPolyId);
	void SpawnAssetfollowingSFX(int* EntityId, int SfxId, int dummyPolyId);
	//2010
	void PlaySoundEvent(int* EntityId, int soundId, SoundType _SoundType);

};