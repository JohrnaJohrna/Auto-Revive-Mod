#include "Talk.h"

using TalkA = EntityINS::EntityModule::Talk;

TalkA::Talk()
{

}

TalkA::Talk(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Talk_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x50, 0x0 });
}

TalkA::~Talk()
{
	Talk_PTR = NULL;
}