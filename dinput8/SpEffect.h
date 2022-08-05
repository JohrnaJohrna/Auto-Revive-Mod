#pragma once

#include "Entity.h"
#include "main.h"

class EntityINS::SpecialEffect {
private:
protected:
	uintptr_t Entity_PTR_Sp;
	uintptr_t EffectListPtr;
public:
	SpecialEffect();
	SpecialEffect(uintptr_t Entity_PTR);
	~SpecialEffect();
	void AddSpEffect(int SpEffectID);
	void DeleteSpEffect(int SpEffectID);
};