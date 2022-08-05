#include "ChrSpawner.h"

using ChrSpawnerA = CHR_INS::ChrSpawner;

ChrSpawnerA::ChrSpawner()
{

}
ChrSpawnerA::ChrSpawner(uintptr_t CHR_INS_BASE)
{
	Memory_S mem;
	_chrInsBase = CHR_INS_BASE;
	ChrSpawnerBASE = mem.GetPointerAddress(CHR_INS_BASE, { 0x185A0, 0x0 });
}
ChrSpawnerA::~ChrSpawner()
{

}

void ChrSpawnerA::CreateCharacter(ChrSpawnerArgs ChrSpawnArg)
{
	Memory_S mem;
	void* MAIN_PTR = (void*)ChrSpawnerBASE;
	int chrID;
	int chrID_Player = 0;
	
	float* PTR_FLOAT = (float*)MAIN_PTR;
	PTR_FLOAT += 0x2C; //0xB0

	int* PTR = (int*)MAIN_PTR;
	PTR += 0x3C;

	wchar_t* PTR_NAME = (wchar_t*)(PTR + 0x4);

	*PTR = ChrSpawnArg.NpcParamID;
	PTR += 0x1;
	*PTR = ChrSpawnArg.NpcThinkParamID;
	PTR += 0x1;
	*PTR = ChrSpawnArg.EventEntityID;
	PTR += 0x1;
	*PTR = ChrSpawnArg.TalkID;

	chrID = ChrSpawnArg.NpcParamID;

	wchar_t ChrName[] = {'c', 'X', 'X', 'X', 'X', 0 };
	int v = 4;

	while (chrID >= 1)
	{
		if (chrID < 10000)
		{
			if (chrID < 10000 && chrID > 1000)
				chrID_Player = chrID;

			ChrName[v] = (chrID % 10) + 0x30;
			v -= 1;
		}

		chrID /= 10;
	}

	if (chrID_Player == 0) //if character you want to spawn is player type (uses extra args)
	{
		int* PTR_PLAYER_CHR = (int*)MAIN_PTR;
		PTR_PLAYER_CHR += 0x5F;
		*PTR_PLAYER_CHR = ChrSpawnArg.CharaParamID;
		PTR_PLAYER_CHR += 0x1;
		*PTR_PLAYER_CHR = (int)ChrSpawnArg.manType;
	}

	float* Position = (float*)mem.GetPointerAddress(_chrInsBase, { 0x18468, 0x190, 0x68, 0x70 }); //local player pos

	for (int i = 0; i < 3; i++)
	{
		*PTR_FLOAT = *Position;
		PTR_FLOAT += 1;
		Position += 1;
	}

	for (int i = 0; i < 6; i++)
	{
		*PTR_NAME = ChrName[i];
		PTR_NAME += 1;
	}

	int* INIT_SPAWN = (int*)MAIN_PTR;
	INIT_SPAWN += 0x11; //0x44
	*INIT_SPAWN = 1;
	
}

void ChrSpawnerA::EraseCharacter(EntityINS eIns)
{
	//0x48, 0x85, 0xD2, 0x0F, 0x84, 0x29, 0x02, 0x00, 0x00, 0x57, 0x48, 0x83, 0xEC, 0x30, 0x48, 0xC7, 0x44, 0x24, 0x20, 0xFE, 0xFF, 0xFF, 0xFF, 0x48, 0x89, 0x5C, 0x24, 40 48 89 74

	Memory_S mem;
	mem.Callx64Function(mem.GetModuleBase() + 0x4FDA20, eIns.GetEntityBase());
}