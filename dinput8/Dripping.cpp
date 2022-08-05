#include "Dripping.h"

using DrippingA = EntityINS::EntityModule::Dripping;

DrippingA::Dripping()
{

}

DrippingA::Dripping(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Dripping_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xD8, 0x0 });
}

DrippingA::~Dripping()
{
	Dripping_PTR = NULL;
}