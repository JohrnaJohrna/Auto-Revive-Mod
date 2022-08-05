#include "AI.h"

using AIA = EntityINS::EntityModule::AI;

AIA::AI()
{

}

AIA::AI(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	AI_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x38, 0x0 });
}

AIA::~AI()
{
	AI_PTR = NULL;
}