#include "SuperArmor.h"

using SuperArmorA = EntityINS::EntityModule::SuperArmor;

SuperArmorA::SuperArmor()
{

}

SuperArmorA::SuperArmor(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	SuperArmor_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x40 });
}

SuperArmorA::~SuperArmor()
{
	SuperArmor_PTR = NULL;
}