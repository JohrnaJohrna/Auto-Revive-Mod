#pragma once

#include "Entity.h"

class EntityINS::EntityModule {
private:
protected:
	uintptr_t entityModule_PTR;
public:
	EntityModule();
	EntityModule(uintptr_t eIns);
	~EntityModule();

	class ChrData;
	class ActionFlag;
	class BehScript;
	class TAE;
	class StatusResist;
	class Behavior;
	class BehaviorSync;
	class AI;
	class SuperArmor;
	class Toughness;
	class Talk;
	class Event;
	class Magic; //player ins
	class Position;
	class FALL;
	class Ladder;
	class ActionRequest;
	class Throw;
	class HitStop;
	class Damage;
	class Material;
	class Knockback;
	class SFX;
	class VFX;
	class BehaviorData;
	//class NULL1;
	class ModelParamModifier;
	class Dripping;
	//class NULL2;
	class Ride;
	class BoneMove;
	class Wetness;
	class AutoHoming;
	class AboveShadow;
	class SwordArts;
	class GrassHit;
	class WheelRotation;
	class CliffWind;
	class NaviMeshCostEffect;
};
