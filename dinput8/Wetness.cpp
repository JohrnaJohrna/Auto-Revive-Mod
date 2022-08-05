#include "Wetness.h"

using WetnessA = EntityINS::EntityModule::Wetness;

WetnessA::Wetness()
{

}

WetnessA::Wetness(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Wetness_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xF8 });
}

WetnessA::~Wetness()
{
	Wetness_PTR = NULL;
}