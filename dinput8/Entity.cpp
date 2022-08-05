#include "Entity.h"
#include "SpEffect.h"
#include "EntityModule.h"

//ENTITY INS
EntityINS::EntityINS()
{

}

void EntityINS::SetEntityBase(uintptr_t basePtr)
{
	Entity_PTR = basePtr;
}

EntityINS::EntityINS(uintptr_t basePtr)
{
	SetEntityBase(basePtr);
	_SpecialEffect = new SpecialEffect(Entity_PTR);
	_EntityModule = new EntityModule(Entity_PTR);
}
EntityINS::~EntityINS()
{
	Entity_PTR = NULL;
	delete _SpecialEffect;
	delete _EntityModule;
}

uintptr_t EntityINS::GetEntityBase()
{
	return Entity_PTR;
}

void EntityINS::SetDbgRoleParamID(int ParamID)
{
	Memory_S Memory_S;
	CHR_PARAM_ID_DBG chr_Dbg;
	int* Val = (int*)Memory_S.GetPointerAddress(Entity_PTR, { chr_Dbg._RoleParamID });
	*Val = ParamID;
}

void EntityINS::SetDbgPhantomParamID(int ParamID)
{
	Memory_S Memory_S;
	CHR_PARAM_ID_DBG chr_Dbg;
	int* Val = (int*)Memory_S.GetPointerAddress(Entity_PTR, { chr_Dbg._PhantomParamID });
	*Val = ParamID;
}

void EntityINS::SetDbgWetParamID(int ParamID)
{
	Memory_S Memory_S;
	CHR_PARAM_ID_DBG chr_Dbg;
	int* Val = (int*)Memory_S.GetPointerAddress(Entity_PTR, { chr_Dbg._WetParamID });
	*Val = ParamID;
}

//ENEMY INS
EnemyINS::EnemyINS()
{

}

EnemyINS::EnemyINS(uintptr_t basePtr)
{
	SetEntityBase(basePtr);
}

EnemyINS::~EnemyINS()
{
	EntityINS::~EntityINS();
}

//PLAYER INS
PlayerINS::PlayerINS()
{

}

PlayerINS::PlayerINS(uintptr_t basePtr)
{
	SetEntityBase(basePtr);
}

PlayerINS::~PlayerINS()
{
	EntityINS::~EntityINS();
}

//LOCAL_PLAYER

LocalPlayer::LocalPlayer()
{

}

LocalPlayer::LocalPlayer(uintptr_t basePtr)
{
	SetEntityBase(basePtr);
}

LocalPlayer::~LocalPlayer()
{
	PlayerINS::~PlayerINS();
}

GlobalPos LocalPlayer::GetGlobalPos()
{
	Memory_S mem;
	char* LocPlayer = (char*)Entity_PTR;
	LocPlayer += 0x6B0;
	float* Data = (float*)LocPlayer;
	GlobalPos _GlobalPos;
	_GlobalPos.X = *Data;
	Data += 1;
	_GlobalPos.Y = *Data;
	Data += 1;
	_GlobalPos.Z = *Data;
	Data += 1;
	_GlobalPos.Radian = *Data;
	Data += 1;
	int* DatMapID = (int*)Data;
	_GlobalPos.MAP_ID = *DatMapID;
	return _GlobalPos;
}

GlobalPos LocalPlayer::GetGlobalPosStable()
{
	Memory_S mem;
	char* LocPlayer = (char*)Entity_PTR;
	LocPlayer += 0x6C4;
	float* Data = (float*)LocPlayer;
	GlobalPos _GlobalPos;

	_GlobalPos.X = *Data;
	Data += 1;
	_GlobalPos.Y = *Data;
	Data += 1;
	_GlobalPos.Z = *Data;
	Data += 1;
	_GlobalPos.Radian = *Data;
	Data += 1;
	int* DatMapID = (int*)Data;
	_GlobalPos.MAP_ID = *DatMapID;

	return _GlobalPos;
}