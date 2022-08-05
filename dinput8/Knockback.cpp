#include "Knockback.h"

using KnockbackA = EntityINS::EntityModule::Knockback;

KnockbackA::Knockback()
{

}

KnockbackA::Knockback(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Knockback_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xA8, 0x0 });
}

KnockbackA::~Knockback()
{
	Knockback_PTR = NULL;
}