#include "Position.h"

using PositionA = EntityINS::EntityModule::Position;

PositionA::Position()
{

}

PositionA::Position(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Position_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x68 });
}

PositionA::~Position()
{
	Position_PTR = NULL;
}