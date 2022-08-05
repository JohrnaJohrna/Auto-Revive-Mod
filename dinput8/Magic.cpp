#include "Magic.h"

using MagicA = EntityINS::EntityModule::Magic;

MagicA::Magic()
{

}

MagicA::Magic(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Magic_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x60, 0x0 });
}

MagicA::~Magic()
{
	Magic_PTR = NULL;
}