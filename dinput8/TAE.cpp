#include "TAE.h"

using TAE_A = EntityINS::EntityModule::TAE;

TAE_A::TAE()
{

}

TAE_A::TAE(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	TAE_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x18 });
}

TAE_A::~TAE()
{
	TAE_PTR = NULL;
}