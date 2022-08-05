#pragma once

#include "Memory_S.h";

enum class ItemType : unsigned int {
	Weapon = 0x00000000,
	Armor = 0x10000000,
	Talismans = 0x20000000,
	Goods = 0x40000000,
	SwordArts = 0x80000000
};

struct AddItemDat {
	ItemType _itemType;
	int ItemID;
	int ItemNum;
};

struct PlayerStats {
	int Vigor;
	int Mind;
	int Endurance;
	int Strength;
	int Dexterity;
	int Intelligence;
	int Faith;
	int Arcane;
};

struct MaxEstusNum {
	int HpEstus;
	int MpEstus;
};

struct SwordArtPoints {
	int ByStr;
	int ByDex;
	int ByInt;
	int ByFaith;
};

class GameData {
private:
	uintptr_t GameDataPTR;
public:
	GameData();
	GameData(uintptr_t PTR);
	~GameData();

	class GameDataElem;
	class PlayerGameData;
	class EventUnk;
	//more classes i dont want to add

	GameDataElem* _GameDataElem;
	PlayerGameData* _PlayerGameData;
	EventUnk* _EventUnk;

	void ChangeCharacterInitParam();
	void AddInventoryItem(AddItemDat ItemData);
	void AddAllItemsByCategory(AddItemDat ItemData);

	void SetClearCount(int NgLvl);
	void SetDbgClearCount(int NgLvl);

	int GetClearCount();
	double GetPlayTime();

};