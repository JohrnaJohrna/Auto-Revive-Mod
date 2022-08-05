#include "Damage.h"

using DamageA = EntityINS::EntityModule::Damage;

DamageA::Damage()
{

}

DamageA::Damage(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Damage_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x98, 0x0 });
}

DamageA::~Damage()
{
	Damage_PTR = NULL;
}