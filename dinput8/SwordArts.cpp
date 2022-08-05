#include "SwordArts.h"

using SwordArtsA = EntityINS::EntityModule::SwordArts;

SwordArtsA::SwordArts()
{

}

SwordArtsA::SwordArts(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	SwordArts_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x110, 0x0 });
}

SwordArtsA::~SwordArts()
{
	SwordArts_PTR = NULL;
}