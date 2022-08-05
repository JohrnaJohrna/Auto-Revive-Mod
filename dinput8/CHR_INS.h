#pragma once

#include "Memory_S.h"

class CHR_INS
{
private:
	int _CurrentSessionTime = 0x18480;
	int _MAP_ID = 0x1847C;
protected:
	uintptr_t CHR_INS_BASE;
public:
	CHR_INS();
	CHR_INS(const CHR_INS& chr_ins); //copy constructor
	~CHR_INS();
	CHR_INS& operator=(const CHR_INS& chr_ins);

	const enum EntityListType {
		EnemyList_Legacy = 0x173C0,
		EnemyList_SpiritSummon = 0x173F0,
		EnemyList_Overworld = 0x183A0,
		EnemyList_DebugCreate = 0x18398,
		EnemyList_Buddy = 0x18460,
		LocalPlayer = 0x18468,
		Horse = 0x18390,
		Session_PC = 0x18380,
		Unk = 0x18388,
		AI_ListUnk = 0x18F30,
	};

	class ChrSpawner;

	ChrSpawner* _ChrSpawner;

	list<uintptr_t> GetEntityList(EntityListType entListType);
	void RespawnAllChr();
	int* GetMAP_ID();
	int* GetCurrentSessionTime();
	//EntityINS

	//
};