#include "Auto-Revive.h"

//return addresses
extern "C" DWORD64 GetPlayer_DeathEventRetAddr(unsigned long long chrPtr)
{
	if (Player_deathEventCall != NULL)
	{
		uintptr_t* PlayerPtr = (uintptr_t*)(*WorldChrMan + 0x1E508);
		if (chrPtr == *PlayerPtr)
			return (Player_deathEventCall + 0x2B4);

		return (Player_deathEventCall + 0xE);
	}
}

extern "C" DWORD64 GetPlayer_KillScoredRetAddr()
{
	if (Player_KillScoredCall != NULL)
		return (Player_KillScoredCall + 0x12);
}

extern "C" DWORD64 GetKillDetection_EstusSubRetAddr(int Type)
{
	if (replaceSpEffectIdInjecCall != NULL)
	{
		if (Type == 1)
			return (replaceSpEffectIdInjecCall + 0x16);
		else
			return (replaceSpEffectIdInjecCall + 0xE);

	}
}

extern "C" DWORD64 HitDetection_Attack_SubRetAddr()
{
	if (HitDetection_Attack_Call != NULL)
		return (HitDetection_Attack_Call + 0xE);
}

extern "C" DWORD64 HitDetection_Bullet_SubRetAddr()
{
	if (HitDetection_Bullet_Call != NULL)
		return (HitDetection_Bullet_Call + 0x14);
}

//patches
extern "C" void Setup_PlayerDeathEvent(unsigned long long chrPtr)
{
	uintptr_t* PlayerPtr = (uintptr_t*)(*WorldChrMan + 0x1E508);
	auto* GameData_PC = (EstusRate*)(*(uintptr_t*)(*GameDataMan + 0x8) + 0x904);
	//add null ptr check maybe

	if (chrPtr == *PlayerPtr)
	{
		EraseSpEffectID(*PlayerPtr, 70);

		uintptr_t* ChrModule = (uintptr_t*)(*PlayerPtr + 0x190);
		if (*ChrModule != NULL)
		{
			static_assert(sizeof(int) == 4);

			auto* chrData = (ChrData*)(*(uintptr_t*)(*ChrModule));
			uintptr_t* EventData = (uintptr_t*)(*ChrModule + 0x58);
			uintptr_t* ThrowData = (uintptr_t*)(*ChrModule + 0x88);
			uintptr_t* ThrowNode = (uintptr_t*)(*ThrowData + 0x10);

			if (*ThrowNode != NULL)
			{
				int* temp_throwState = (int*)(*ThrowNode + 0x68);
				*temp_throwState = 0; //reset death throw state
			}

			if (chrData != nullptr) {
				chrData->hp = chrData->maxHp;
				chrData->fp = chrData->maxFp;
			}

			if (*EventData != NULL)
			{ //play respawn animation
				int* temp_anim = (int*)(*EventData + 0x18);
				*temp_anim = 60260;
				isRespawning = false;
			}

		}

		LawOfRegression(PlayerPtr);
		if (GameData_PC->HpEstus_Add == 1)
			RestoreFlask(*PlayerPtr);

		ApplySpEffectID(*PlayerPtr, 999999999, false);

	}
}

extern "C" void Setup_KillScoredPc(unsigned long long targetPtr)
{
	uintptr_t* PlayerPtr = (uintptr_t*)(*WorldChrMan + 0x1E508);
	int PcHandleId = getHandleID(*PlayerPtr);
	int TargetHandleId = getHandleID(targetPtr);

	if (PcHandleId < TargetHandleId && PcHandleId + 6 > TargetHandleId) //check if its a player (in range of player handle ids)
	{
		int KilledHandleId = getKilledHandleID(targetPtr);
		if (PcHandleId == KilledHandleId); //if we are the killer of this player proceed
		{
			if (getSeamlessTeamId(*PlayerPtr) != -1 &&
				getSeamlessTeamId(targetPtr) != -1 &&
				getSeamlessTeamId(*PlayerPtr) != getSeamlessTeamId(targetPtr)) //if our/killed player chr have teams assigned and our teams dont match proceed
			{
				ApplySpEffectID(*PlayerPtr, 99800, false);
			}
		}

		setKilledHandleID(targetPtr, 0);
	}
}

extern "C" void Setup_KillDetection_Estus(int spEffectId)
{
	if (spEffectId == 1300)
	{
		uintptr_t* PlayerPtr = (uintptr_t*)(*WorldChrMan + 0x1E508);
		for(int i = 0; i < 2; i++)
			RestoreEstus(*PlayerPtr, i + 1, 1);
	}
}

extern "C" void Setup_HitDetection_Attack(uintptr_t attackerPtr, uintptr_t defenderPtr)
{
	uintptr_t* PlayerPtr = (uintptr_t*)(*WorldChrMan + 0x1E508);
	if (*PlayerPtr == attackerPtr)
		setKilledHandleID(defenderPtr, getHandleID(attackerPtr));
	else
		setKilledHandleID(defenderPtr, 0);
}

extern "C" void Setup_HitDetection_Bullet(uintptr_t attackerPtr, uintptr_t defenderPtr)
{
	uintptr_t* PlayerPtr = (uintptr_t*)(*WorldChrMan + 0x1E508);
	if (*PlayerPtr == attackerPtr)
		setKilledHandleID(defenderPtr, getHandleID(attackerPtr));
	else
		setKilledHandleID(defenderPtr, 0);
}
//other

int getHandleID(uintptr_t _ChrPtr)
{
	int handleId = *(int*)(_ChrPtr + 0x8);
	return handleId;
}

int getKilledHandleID(uintptr_t _ChrPtr)
{
	int handleId = *(int*)(_ChrPtr + 0x60);
	return handleId;
}

void setKilledHandleID(uintptr_t _ChrPtr, int handleId)
{
	int* KilledHandleId = (int*)(_ChrPtr + 0x60);
	*KilledHandleId = handleId;
}

int getSeamlessTeamId(uintptr_t _ChrPtr)
{
	uintptr_t* FuncPtr = (uintptr_t*)(_ChrPtr);
	FuncPtr = (uintptr_t*)(*FuncPtr + 0x4D0);
	return x64_class.Callx64Function_GetInt(*FuncPtr, _ChrPtr);
}