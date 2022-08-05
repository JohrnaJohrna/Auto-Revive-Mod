#include "BoneMove.h"

using BoneMoveA = EntityINS::EntityModule::BoneMove;

BoneMoveA::BoneMove()
{

}

BoneMoveA::BoneMove(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	BoneMove_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xF0, 0x0 });
}

BoneMoveA::~BoneMove()
{
	BoneMove_PTR = NULL;
}