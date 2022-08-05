#pragma once

#include "CHR_INS.h"
#include "Entity.h"

enum class ManipulatorType : int {
	Chr = 0,
	Pad = 1,
	Network = 2,
	//Replay = 3, crashes game
	Computer = 5,
	Follow = 7
};

struct ChrSpawnerArgs {
	int NpcParamID = 0;
	int NpcThinkParamID = 0;
	int EventEntityID = 0;
	int TalkID = 0;
	int CharaParamID = 0;
	ManipulatorType manType = (ManipulatorType)0;
};

class CHR_INS::ChrSpawner {
private:
protected:
	uintptr_t ChrSpawnerBASE;
	uintptr_t _chrInsBase;
public:

	ChrSpawner();
	ChrSpawner(uintptr_t CHR_INS_BASE);
	~ChrSpawner();
	void CreateCharacter(ChrSpawnerArgs chrSpawnArg);
	void EraseCharacter(EntityINS eIns);
};