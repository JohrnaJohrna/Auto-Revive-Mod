#include "Auto-Revive.h"

//patch
DWORD64 Player_deathEventCall = NULL;
DWORD64 Player_KillScoredCall = NULL;
DWORD64 replaceSpEffectIdInjecCall = NULL; //replaceSpEffectIdInjec_Sig
DWORD64 HitDetection_Attack_Call = NULL;
DWORD64 HitDetection_Bullet_Call = NULL;
//func
uintptr_t SpEffect_Add_Addr = NULL;
uintptr_t SpEffect_Erase_Addr = NULL;
uintptr_t RestoreEstus_CALL = NULL;
uintptr_t RestoreFlasks_CALL = NULL;
uintptr_t RestoreItemsFromInfBox_CALL = NULL;
uintptr_t WarpPlayer_Call = NULL;
//classes
uintptr_t* WorldChrMan = nullptr; //base address itself
uintptr_t* GameDataMan = nullptr;
uintptr_t* ParamMan = nullptr;
uintptr_t* CsSoundMan = nullptr;
uintptr_t* FieldArea = nullptr;

bool isRespawning = true;
bool isWarping = true;

void Auto_Revive_Main()
{
	ScanSignatures(); //setup function

	SetupParams();

	PatchExecutable();

	while (true)
	{
		/**/
		if (*FieldArea != NULL)
		{
			if (*(uintptr_t*)(*FieldArea + 0x190) != NULL)
			{
				uintptr_t* PlayerPtr = (uintptr_t*)(*WorldChrMan + 0x1E508);
				if (*PlayerPtr != NULL)
				{
					uintptr_t* ChrModule = (uintptr_t*)(*PlayerPtr + 0x190);

					uintptr_t* TaeModule = (uintptr_t*)(*ChrModule + 0x18);
					
					uintptr_t* I_FramesPtr = (uintptr_t*)(*TaeModule + 0x10);
					if (*I_FramesPtr != NULL)
					{
						I_FramesPtr = (uintptr_t*)(*I_FramesPtr + 0xA0);
						I_FramesPtr = (uintptr_t*)(*I_FramesPtr + 0x10);
						I_FramesPtr = (uintptr_t*)(*I_FramesPtr + 0x08);
						I_FramesPtr = (uintptr_t*)(*I_FramesPtr + 0x18);

						float* tempIframeEventDur = (float*)(*I_FramesPtr + 0x28EE78);
						*tempIframeEventDur = (float)3;
					}
					
					int* temp_CurrAnimId = (int*)(*TaeModule + 0x20);
					uintptr_t* CsSoundManPtr = (uintptr_t*)(*CsSoundMan + 0x328);
					uintptr_t* EventModule = (uintptr_t*)(*ChrModule + 0x58);

					if (*temp_CurrAnimId == 60260 && isRespawning == false) //respawn
					{
						isRespawning = true;
						Sleep(3000);

						LawOfRegression(PlayerPtr);
						ApplySpEffectID(*PlayerPtr, 1110, false);

						int* temp_EventAnimId = (int*)(*EventModule + 0x18);
						*temp_EventAnimId = 63021;
					}
					else if (*temp_CurrAnimId == 80921 && *(int*)(*CsSoundManPtr + 0x1D8) == 0) //IsBonfire Logic
					{
						int* temp_EventAnimId = (int*)(*EventModule + 0x18);
						*temp_EventAnimId = 63000;

						ApplySpEffectID(*PlayerPtr, 1210, false);
						RestoreFlask(*PlayerPtr);
						ResetInventory();
					}
					else if (*temp_CurrAnimId == 80730 && isWarping == false)
					{
						isWarping = true;
						Sleep(2000);
						int eventEntityId = 0;
						WarpPlayer(45, 1, 0, 0, &eventEntityId);
					}
					else if (*temp_CurrAnimId != 80730)
					{
						isWarping = false;
					}

					uintptr_t* OtherPlayersBase = (uintptr_t*)(*WorldChrMan + 0x1E1A8);
					OtherPlayersBase = (uintptr_t*)(*OtherPlayersBase + 0x18);
					uintptr_t* tempPlayer = nullptr;
					if (*OtherPlayersBase != NULL)
					{
						for (int i = 0; i < 6; i++)
						{
							tempPlayer = (uintptr_t*)(*OtherPlayersBase + (i * 0x10));
							if(*tempPlayer != NULL)
								setDebugColorId(*tempPlayer, getSeamlessTeamId(*tempPlayer)); //0x64
						}
					}

					uintptr_t* GameDataMan_PCPtr = (uintptr_t*)(*GameDataMan + 0x8);
					uintptr_t* Inventory_PcPtr = (uintptr_t*)(*GameDataMan_PCPtr + 0x448); //0x2B0 + 0x158 + 0x40
					auto* InventoryArray = (InventoryData*)(*Inventory_PcPtr);
					auto* EstusPreset = (EstusRate*)(*GameDataMan_PCPtr + 0x904);

					if (EstusPreset->HpEstus_Add != 1)
					{
						while (InventoryArray->ItemId_Inventory != -1)
						{
							if (InventoryArray->ItemId_Param == 0x40000401) //+12 lvl hp flask
							{
								EstusPreset->HpEstusRate = 0.0f;
								EstusPreset->HpEstus_Add = 1;
								InventoryArray->ItemNum = 1;
							}
							else if (InventoryArray->ItemId_Param == 0x40000433) //+12 Mana flask
							{
								EstusPreset->FpEstusRate = 0.0f;
								EstusPreset->FpEstus_Add = 1;
								InventoryArray->ItemNum = 1;
							}
							InventoryArray++;
						}
					}
				}
			}
		}
	}
}

void ApplySpEffectID(uintptr_t ChrPtr, int SpEffectID, bool isOffline)
{
	if (SpEffect_Add_Addr != NULL)
		x64_class.Callx64Function(SpEffect_Add_Addr, ChrPtr, SpEffectID, isOffline);
}

void EraseSpEffectID(uintptr_t ChrPtr, int SpEffectID)
{
	ChrPtr = *(uintptr_t*)(ChrPtr + 0x178);
	if (SpEffect_Erase_Addr != NULL)
		x64_class.Callx64Function(SpEffect_Erase_Addr, ChrPtr, SpEffectID);
}

void LawOfRegression(uintptr_t* PlayerPtr)
{
	int SpEffectIds[31] = { 503041, 1673000, 1673001, 1673002, 1673003, 1673004, 1673005, 1673006,
		1673007, 1673008, 1673009, 1673010, 1673011, 1673012, 1673013, 1673014,
		1673020, 1673021, 1673022, 1673023, 1673024, 1673025, 1673026, 1673027,
		1673028, 1673029, 1673030, 1673031, 1673032, 1673033, 1673034 };

	for (int i = 0; i < 31; i++)
		ApplySpEffectID(*PlayerPtr, SpEffectIds[i], false);
}

void RestoreFlask(uintptr_t ChrPtr)
{
	if (RestoreFlasks_CALL != NULL)
		x64_class.Callx64Function(RestoreFlasks_CALL, ChrPtr);
}

void RestoreEstus(uintptr_t ChrPtr, char type, char num)
{
	if (RestoreEstus_CALL != NULL)
		x64_class.Callx64Function(RestoreEstus_CALL, ChrPtr, type, num);
}

void ResetInventory()
{
	if(RestoreItemsFromInfBox_CALL != NULL)
		x64_class.Callx64Function(RestoreItemsFromInfBox_CALL);
}

void ScanSignatures()
{
	//patch
	Player_deathEventCall = x64_class.GetSignature(PlayerDeathEvent_Sig);
	Player_KillScoredCall = x64_class.GetSignature(KillScored_Sig);
	replaceSpEffectIdInjecCall = x64_class.GetSignature(replaceSpEffectIdInjec_Sig);
	HitDetection_Attack_Call = x64_class.GetSignature(HitDetection_Attack_Sig);
	HitDetection_Bullet_Call = x64_class.GetSignature(HitDetection_Bullet_Sig);
	//func
	SpEffect_Add_Addr = x64_class.GetSignature(SpEffectAdd_Sig);
	SpEffect_Erase_Addr = x64_class.GetSignature(SpEffectErase_Sig);
	RestoreEstus_CALL = x64_class.GetSignature(RestoreEstus_Sig);
	RestoreFlasks_CALL = x64_class.GetSignature(RestoreFlasks_Sig);
	RestoreItemsFromInfBox_CALL = x64_class.GetSignature(RestoreItemsFromInfBox_Sig);
	WarpPlayer_Call = x64_class.GetSignature(WarpPlayer_Sig);
	//classes
	WorldChrMan = (uintptr_t*)x64_class.GetSignature_BaseAddr(WorldChrMan_Sig, { 0x3, 0x7 }); //base address itself
	GameDataMan = (uintptr_t*)x64_class.GetSignature_BaseAddr(GameDataMan_Sig, { 0x3, 0x7 });
	ParamMan = (uintptr_t*)x64_class.GetSignature_BaseAddr(ParamMan_Sig, { 0x3, 0x7 });
	CsSoundMan = (uintptr_t*)x64_class.GetSignature_BaseAddr(CsSoundMan_Sig, { 0x3, 0x7 });
	FieldArea = (uintptr_t*)x64_class.GetSignature_BaseAddr(FieldArea_Sig, { 0x3, 0x7 });
}

void SetupParams()
{

	while (*ParamMan == NULL) //sanity check
	{

	}

	auto* InvisEffect = (SpEffectParam*)GetPointerToParamOffset(0x4C0, 999999999);
	InvisEffect->effectEndurance = 8.56000042;
	InvisEffect->fireDamageCutRate = 1.0f;
	InvisEffect->spCategory = 0;
	InvisEffect->stateInfo = 0;
	InvisEffect->bool_0x16C = 4;
	InvisEffect->vfxId1 = 8526;
	InvisEffect->vfxId2 = 1467000;
	auto* KillSecured_Effect = (SpEffectParam*)GetPointerToParamOffset(0x4C0, 99800);
	KillSecured_Effect->effectEndurance = 4.0f;
	KillSecured_Effect->replaceSpEffectId = 1300;
	auto* EstusEffectRegainedEffect = (SpEffectParam*)GetPointerToParamOffset(0x4C0, 1300);
	EstusEffectRegainedEffect->ChangeFpRate = 0.0f;
	EstusEffectRegainedEffect->ChangeHpRate = 0.0f;
	auto* ArenaExplosionEffect = (SpEffectParam*)GetPointerToParamOffset(0x4C0, 1110);
	ArenaExplosionEffect->effectEndurance = 5.71f; //5.666666508f

	auto* SeamlessBlue = (PhantomParam*)GetPointerToParamOffset(0xE98, 201);
	auto* VanillaBlue = (PhantomParam*)GetPointerToParamOffset(0xE98, 70);
	*SeamlessBlue = *VanillaBlue;
	auto* SeamlessRed = (PhantomParam*)GetPointerToParamOffset(0xE98, 202);
	auto* VanillaRed = (PhantomParam*)GetPointerToParamOffset(0xE98, 60);
	*SeamlessRed = *VanillaRed;
	//add struct for params
}

uintptr_t* GetPointerToParamOffset(int ParamOffsetId, int ParamId)
{
	uintptr_t* ParamManPtr = (uintptr_t*)(*ParamMan + ParamOffsetId);

	while (*ParamManPtr == NULL) //sanity check
	{

	}

	ParamManPtr = (uintptr_t*)(*ParamManPtr + 0x80);
	ParamManPtr = (uintptr_t*)(*ParamManPtr + 0x80);
	short RowCount = *(short*)(*ParamManPtr + 0xA);

	uintptr_t* ParamManPtr_temp = (uintptr_t*)(*ParamManPtr + 0x40);
	int tempId = 0;
	int tempRowOffset = 0;

	for (int i = 0; i < (int)RowCount; i++)
	{
		tempId = *(int*)(ParamManPtr_temp);
		if (tempId == ParamId)
		{
			tempRowOffset = *(int*)(ParamManPtr_temp + 0x1);
			break;
		}
		ParamManPtr_temp = (uintptr_t*)(*ParamManPtr + 0x40 + (0x18 * (i+1)));
	}

	return (uintptr_t*)(*ParamManPtr + tempRowOffset);
}

void PatchExecutable()
{
	unsigned char JmpBytes[] = {
	0xff, 0x25, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
	};

	memcpy((void*)Player_deathEventCall, ConvertAddr((unsigned char*)JmpBytes, (uintptr_t)Player_DeathEventSub), 14);
	memcpy((void*)Player_KillScoredCall, ConvertAddr((unsigned char*)JmpBytes, (uintptr_t)Player_KillScoredSub), 14);
	memcpy((void*)replaceSpEffectIdInjecCall, ConvertAddr((unsigned char*)JmpBytes, (uintptr_t)KillDetection_EstusSub), 14);
	memcpy((void*)HitDetection_Attack_Call, ConvertAddr((unsigned char*)JmpBytes, (uintptr_t)HitDetection_Attack_Sub), 14);
	memcpy((void*)HitDetection_Bullet_Call, ConvertAddr((unsigned char*)JmpBytes, (uintptr_t)HitDetection_Bullet_Sub), 14);
}

unsigned char* ConvertAddr(unsigned char* ByteArray, uintptr_t Addr)
{
	unsigned char* MyLong = ByteArray;
	memcpy((void*)(MyLong + 0x6), &Addr, 8);
	return MyLong;
}

void setDebugColorId(uintptr_t _ChrPtr, int colorId)
{
	int* setTeamId = (int*)(_ChrPtr + 0x64);
	*setTeamId = colorId;
}

void WarpPlayer(int AreaId, int BlockId, int RegionId, int IndexId, int* EventEntityId)
{
	if(WarpPlayer_Call != NULL)
		x64_class.Callx64Function(WarpPlayer_Call, AreaId, BlockId, RegionId, IndexId, EventEntityId);
}