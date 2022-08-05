#pragma once

#include "GameData.h"

class GameData::PlayerGameData {
private:
public:
	PlayerGameData();
	~PlayerGameData();

	class EquipGameData;
	class FaceData;
	class Unk8E0;
	class Unk938;
	class MenuRefSpecialEffect1;
	class MenuRefSpecialEffect2;
	class MenuRefSpecialEffect3;
	class EquipInventoryData;
	class GestureGameData;
	class RideGameData;
	class WorldCheckStringInternal1;
	class WorldCheckStringInternal2;
	class ExParamSolver;

	EquipGameData* _EquipGameData;
	FaceData* _FaceData;
	Unk8E0* _Unk8E0;
	Unk938* _Unk938;
	MenuRefSpecialEffect1* _MenuRefSpecialEffect1;
	MenuRefSpecialEffect2* _MenuRefSpecialEffect2;
	MenuRefSpecialEffect3* _MenuRefSpecialEffect3;
	EquipInventoryData* _EquipInventoryData;
	GestureGameData* _GestureGameData;
	RideGameData* _RideGameData;
	WorldCheckStringInternal1* _WorldCheckStringInternal1;
	WorldCheckStringInternal2* _WorldCheckStringInternal2;
	ExParamSolver* _ExParamSolver;

	void SetSexType(char _SexType);
	void SetLvl(int Lvl);
	void SetRuneNum(int RuneNum);
	void SetPlayerStats(PlayerStats _PlayerStats);
	void SetMaxEstus(MaxEstusNum _estusNum);
	void SetSwordArtPoints(SwordArtPoints _SwordArtPoints);

	char GetArcheType();
	char GetVoiceType();
	char GetSexType();
	int GetRuneNum();
	int GetTotalRuneNum();
	int GetLvl();
	int GetPlayerNo();
	wchar_t* GetChrName();
	PlayerStats GetPlayerStats();
	PlayerStats GetCorrectionPlayerStats();
	MaxEstusNum GetMaxEstus();
	SwordArtPoints GetSwordArtPoints();
};

class PlayerGameData_LocalPlayer : public GameData::PlayerGameData {
private:
public:
	PlayerGameData_LocalPlayer();
	~PlayerGameData_LocalPlayer();

	void SetHostMode(bool _State); //furcalling finger
	void SetRuneArc(bool _State);
	void SetWhiteCipherRing(bool _State);
	void SetBlueCipherRing(bool _State);
	void SetMatchmakingWeaponLvl(char weaponLvl);
	void SetSoloBreakinPoint(int BreakInPoint);


};