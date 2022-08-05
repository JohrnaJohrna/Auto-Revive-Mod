#pragma once

#include "CHR_INS.h"

struct GlobalPos {
	float X = 0.0f;
	float Y = 0.0f;
	float Z = 0.0f;
	float Radian = 0.0f;
	int MAP_ID = 0;
};

class EntityINS
{
private:
	int _HandleID = 0x08;
	int _ChrFadeOut = 0x20;
	int _CHR_TYPE = 0x68;
	int _TEAM_TYPE = 0x6C;
	int _UnkHandleID = 0x70;
	int _NetworkHandleID = 0x74;
	int _ChrID = 0x188;
	int _EventEntityID = 0x1E4;
	int _DebugFlag0x0 = 0x520;
	int _DebugFlag0x1 = 0x521;
	int _DebugFlag0x2 = 0x522;
	int _DebugFlag0x3 = 0x523;
	int _EnableChrDraw = 0x61C;
	int _IsHorse = 0x68C;

	struct DrawGroup {
		vector<int> DrawGroups = { 0x24C, 0x250, 0x254, 0x258, 0x25C, 0x260, 0x264, 0x268 };
		vector<int> DispGroups = { 0x26C, 0x270, 0x274, 0x278, 0x27C, 0x280, 0x284, 0x288 };
		vector<int> BackReadGroups = { 0x28C, 0x290, 0x294, 0x298, 0x29C, 0x2A0, 0x2A4, 0x2A8 };
	};

	struct Debug_DISP {
		int _DispStableGround = 0x6F5;
		int _BloodstainDisp = 0x6F1;
		int _UnkDisp1 = 0x6F2;
		int _UnkDisp2 = 0x6F3;
		int _UnkDisp3 = 0x6F4;
	};

	int _RoleParamID_force = 0x534; //debug flag 0x1(5)

	struct CHR_PARAM_ID_DBG {
		int _RoleParamID = 0x204;
		int _PhantomParamID = 0x528;
		int _WetParamID = 0x52C;
	};

	int _DisablePartsRender = 0x6F6;
	int _CastShadow = 0x248;
	int _MotionBlur = 0x249;

	struct MapMimicry {
		int _VariationType = 0x20C;
		int _ParamID = 0x210;
	};

	struct currLocation {
		int _MAP_ID = 0x6D4;
		int _PlayRegionID = 0x6D8;
	};

	int _PlayRegionID = 0x2E4;

protected:
	uintptr_t Entity_PTR;
public:
	EntityINS();
	EntityINS(uintptr_t basePtr);
	~EntityINS();

	class ChrFinder {

	};

	class ChrRes {

	};

	class SpecialEffect;

	SpecialEffect* _SpecialEffect;

	class Unk2 {
		//0x198
	};

	class HkAi {

	};

	class EntityModule;

	EntityModule* _EntityModule;

	uintptr_t GetEntityBase();

	int GetHandleID();
	int GetChrType();
	int GetTeamType();
	int GetNetworkHandle();
	int GetChrID();
	currLocation getCurrentLocation();

	void SetEntityBase(uintptr_t basePtr);

	void SetChrType();
	void SetTeamType();
	void SetDbgRoleParamID(int ParamID);
	void SetDbgPhantomParamID(int ParamID);
	void SetDbgWetParamID(int ParamID);
};

class PlayerINS : public EntityINS {
private:

protected:
	int _TAE_MOVESET = 0x620;
public:
	PlayerINS();
	PlayerINS(uintptr_t basePtr);
	~PlayerINS();
};

class EnemyINS : public EntityINS {
private:
	int _comManipulator = 0x570;
	int _NetAiManipulator = 0x578;
	int _RideManipulator = 0x580;
	int _mapStudioSpEffectEquip = 0x5A0;

	struct MapStudioSpEffectEquip {
		vector<int> SpEffects = { 0x0, 0x4, 0x8, 0xC, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38, 0x3C };
	};

	int _NpcSpEffectEquip = 0x598;

	struct NpcSpEffectEquip {
		vector<int> SpEffects = { 0x0, 0x4, 0x8, 0xC, 0x10, 0x14, 0x18, 0x1C, 0x20, 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38, 0x3C,
		0x40, 0x44, 0x48, 0x4C, 0x50, 0x54, 0x58, 0x5C, 0x60, 0x64, 0x68, 0x6C, 0x70, 0x74, 0x78, 0x7C };
	};

protected:

public:
	EnemyINS();
	EnemyINS(uintptr_t basePtr);
	~EnemyINS();
};

class LocalPlayer : public PlayerINS {
private:
protected:
public:
	LocalPlayer();
	LocalPlayer(uintptr_t basePtr);
	~LocalPlayer();
	GlobalPos GetGlobalPos();
	GlobalPos GetGlobalPosStable();
};