#pragma once

//worldChrMan

#include "CHR_DBG.h"
//#include "CHR_INS.h"
#include "EntityModule.h" //remove?
#include "Entity.h"
#include "ChrData.h"
#include "SpEffect.h"
#include "ChrSpawner.h"
//gamedata
#include "GameData_LocalPlayer.h"
//event
#include "EventCMD.h"

class GAME {
private:
public:
	GAME();
	~GAME();

	CHR_INS* _CHRINS;
	CHR_DBG* _CHRDBG;
	GEvent* _Event;
};