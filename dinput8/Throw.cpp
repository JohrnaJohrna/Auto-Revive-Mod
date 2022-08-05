#include "Throw.h"

using ThrowA = EntityINS::EntityModule::Throw;

ThrowA::Throw()
{

}

ThrowA::Throw(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Throw_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x88, 0x0 });
}

ThrowA::~Throw()
{
	Throw_PTR = NULL;
}