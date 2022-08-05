#include "AboveShadow.h"

using AboveShadowA = EntityINS::EntityModule::AboveShadow;

AboveShadowA::AboveShadow()
{

}

AboveShadowA::AboveShadow(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	AboveShadow_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x108, 0x0 });
}

AboveShadowA::~AboveShadow()
{
	AboveShadow_PTR = NULL;
}