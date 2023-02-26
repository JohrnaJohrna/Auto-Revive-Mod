#pragma once

#include "../x64mem.h"
//patch
static x64mem x64_class;

extern DWORD64 Player_deathEventCall;
extern DWORD64 Player_KillScoredCall;
extern DWORD64 replaceSpEffectIdInjecCall;
extern DWORD64 HitDetection_Attack_Call;
extern DWORD64 HitDetection_Bullet_Call;
//func
extern uintptr_t SpEffect_Add_Addr;
extern uintptr_t SpEffect_Erase_Addr;
extern uintptr_t RestoreEstus_CALL;
extern uintptr_t RestoreFlasks_CALL;
extern uintptr_t RestoreItemsFromInfBox_CALL;
extern uintptr_t WarpPlayer_Call;
//classes
extern uintptr_t* WorldChrMan; //base address itself
extern uintptr_t* GameDataMan;
extern uintptr_t* ParamMan;
extern uintptr_t* CsSoundMan;
extern uintptr_t* FieldArea;
extern bool isRespawning;
extern bool isWarping;

extern "C" void __fastcall Player_DeathEventSub();
extern "C" void __fastcall Player_KillScoredSub();
extern "C" void __fastcall HitDetection_Attack_Sub();
extern "C" void __fastcall HitDetection_Bullet_Sub();
extern "C" void __fastcall KillDetection_EstusSub();

void Auto_Revive_Main();
void ApplySpEffectID(uintptr_t ChrPtr, int SpEffectID, bool isOffline);
void RestoreFlask(uintptr_t ChrPtr);
void RestoreEstus(uintptr_t ChrPtr, char type, char num);
void EraseSpEffectID(uintptr_t ChrPtr, int SpEffectID);
void LawOfRegression(uintptr_t* PlayerPtr);
void ResetInventory();
void ScanSignatures();
void PatchExecutable();
int getHandleID(uintptr_t _ChrPtr);
int getKilledHandleID(uintptr_t _ChrPtr);
void setKilledHandleID(uintptr_t _ChrPtr, int handleId);
void setDebugColorId(uintptr_t _ChrPtr, int colorId);
void WarpPlayer(int AreaId, int BlockId, int RegionId, int IndexId, int* EventEntityId);
int getSeamlessTeamId(uintptr_t _ChrPtr);
unsigned char* ConvertAddr(unsigned char* Arg1, uintptr_t Addr);
void SetupParams();
uintptr_t* GetPointerToParamOffset(int ParamOffsetId, int ParamId);

struct ChrData {
	char _0[0x138];
	int hp;     // 0x138
	int maxHp;  // 0x13C
	char _1[0x8];
	int fp;     // 0x148
	int maxFp;  // 0x14C
};

struct InventoryData {
	int ItemId_Inventory;
	int ItemId_Param;
	int ItemNum;
	int Unk1;
	int Unk2;
};

struct EstusRate {
	float HpEstusRate;
	int HpEstus_Add;
	float FpEstusRate;
	int FpEstus_Add;
};

struct SpEffectParam {
	char _0[0x8];
	float effectEndurance;
	char _1[0x24];
	float fireDamageCutRate;
	char _2[0x68];
	float ChangeHpRate;
	char _3[0x4];
	float ChangeFpRate;
	char _4[0x7C];
	int replaceSpEffectId;
	char _4_1[0x16];
	short spCategory;
	char _5[0x16];
	short stateInfo;
	char _6[0x14];
	char bool_0x16C;
	char _7[0x3];
	int vfxId1;
	char _8[0x18];
	int vfxId2;
};

struct PhantomParam {
	float edgeAlpha;
	float frontAlpha;
	float diffMulAlpha;
	float specMulAlpha;
	float lightAlpha;
	unsigned char edgeR;
	unsigned char edgeG;
	unsigned char edgeB;
	unsigned char frontR;
	unsigned char frontG;
	unsigned char frontB;
	unsigned char diffMulR;
	unsigned char diffMulG;
	unsigned char diffMulB;
	unsigned char specMulR;
	unsigned char specMulG;
	unsigned char specMulB;
	unsigned char lightAlphaR;
	unsigned char lightAlphaG;
	unsigned char lightAlphaB;
	float Alpha;
	float blendRate;
	char blendType;
	bool isEdgeSubtract;
	bool isFrontSubtract;
	bool isNo2Pass;
	float edgePower;
	float glowScale;
};