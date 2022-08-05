#include "NaviMeshCostEffect.h"

using NaviMeshCostEffectA = EntityINS::EntityModule::NaviMeshCostEffect;

NaviMeshCostEffectA::NaviMeshCostEffect()
{

}

NaviMeshCostEffectA::NaviMeshCostEffect(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	NaviMeshCostEffect_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x130 });
}

NaviMeshCostEffectA::~NaviMeshCostEffect()
{
	NaviMeshCostEffect_PTR = NULL;
}