#include "Toughness.h"

using ToughnessA = EntityINS::EntityModule::Toughness;

ToughnessA::Toughness()
{

}

ToughnessA::Toughness(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Toughness_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x48 });
}

ToughnessA::~Toughness()
{
	Toughness_PTR = NULL;
}