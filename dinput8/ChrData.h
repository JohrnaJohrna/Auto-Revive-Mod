#pragma once

#include "EntityModule.h"

class EntityINS::EntityModule::ChrData {
private:
	int DebugFlag0x1 = 0x19B;
protected:
	uintptr_t chrData_PTR;
public:
	const enum DebugFlagState {
		NoDead = 0x0,
		NoDamage = 0x1,
		NoFpConsume = 0x2,
		NoStaminaConsume = 0x3,
	};

	const struct BaseAttributes {
		int HP;
		int MaxHP;
		int FP;
		int MaxFP;
		int SP;
		int MaxSP;
	};
	ChrData();
	~ChrData();
	ChrData(EntityINS::EntityModule eModule);

	BaseAttributes GetBasicParameters();
	void SetBasicParameters(BaseAttributes basicData);
	void SetDebugFlag(DebugFlagState flagState);
};