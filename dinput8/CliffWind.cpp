#include "CliffWind.h"

using CliffWindA = EntityINS::EntityModule::CliffWind;

CliffWindA::CliffWind()
{

}

CliffWindA::CliffWind(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	CliffWind_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x128, 0x0 });
}

CliffWindA::~CliffWind()
{
	CliffWind_PTR = NULL;
}