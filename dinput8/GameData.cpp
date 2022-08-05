#include "GameData.h"
#include "GameData_LocalPlayer.h";

GameData::GameData()
{
	
}

GameData::GameData(uintptr_t PTR)
{
	GameDataPTR = PTR;
	_PlayerGameData = new PlayerGameData();
}

GameData::~GameData()
{
	delete _PlayerGameData;
}