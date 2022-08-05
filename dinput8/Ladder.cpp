#include "Ladder.h"

using LadderA = EntityINS::EntityModule::Ladder;

LadderA::Ladder()
{

}

LadderA::Ladder(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Ladder_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x20, 0x0 });
}

LadderA::~Ladder()
{
	Ladder_PTR = NULL;
}