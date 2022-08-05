#include "SpEffect.h"
#include "FunctionSignatures.h"

using SpecialEffectA = EntityINS::SpecialEffect;

SpecialEffectA::SpecialEffect()
{

}

SpecialEffectA::SpecialEffect(uintptr_t Entity_PTR)
{
	Memory_S mem;
	Entity_PTR_Sp = Entity_PTR;
	EffectListPtr = mem.GetPointerAddress(Entity_PTR, { 0x178, 0x0 });
}

SpecialEffectA::~SpecialEffect()
{

}

void SpecialEffectA::AddSpEffect(int SpEffectID)
{
	Memory_S mem;

	uintptr_t SigAddr = mem.GetSignature(SpEffectAdd);

	mem.Callx64Function(SigAddr, Entity_PTR_Sp, SpEffectID);
}

void SpecialEffectA::DeleteSpEffect(int SpEffectID)
{
	Memory_S mem;
	uintptr_t SigAddr = mem.GetSignature(SpEffectErase);

	mem.Callx64Function(SigAddr, EffectListPtr, SpEffectID);
}