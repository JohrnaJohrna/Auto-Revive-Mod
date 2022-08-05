#include "Material.h"

using MaterialA = EntityINS::EntityModule::Material;

MaterialA::Material()
{

}

MaterialA::Material(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	Material_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0xA0 });
}

MaterialA::~Material()
{
	Material_PTR = NULL;
}