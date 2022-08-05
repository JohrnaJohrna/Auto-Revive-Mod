#include "ChrData.h"

using ChrDataA = EntityINS::EntityModule::ChrData;

ChrDataA::ChrData()
{

}

ChrDataA::ChrData(EntityINS::EntityModule eModule)
{
	Memory_S memory;
	chrData_PTR = memory.GetPointerAddress(eModule.entityModule_PTR, { 0x0, 0x0 });
}

ChrDataA::~ChrData()
{
	chrData_PTR = NULL;
}

ChrDataA::BaseAttributes ChrDataA::GetBasicParameters()
{
	Memory_S memory;
	BaseAttributes Value;

	Value.HP = *(int*)memory.GetPointerAddress(chrData_PTR, { 0x138 });
	Value.MaxHP = *(int*)memory.GetPointerAddress(chrData_PTR, { 0x144 });
	Value.FP = *(int*)memory.GetPointerAddress(chrData_PTR, { 0x148 });
	Value.MaxFP = *(int*)memory.GetPointerAddress(chrData_PTR, { 0x150 });
	Value.SP = *(int*)memory.GetPointerAddress(chrData_PTR, { 0x154 });
	Value.MaxSP = *(int*)memory.GetPointerAddress(chrData_PTR, { 0x15C });

	return Value;
}

void ChrDataA::SetBasicParameters(BaseAttributes basicData)
{
	Memory_S memory;

	int* Ptr = (int*)memory.GetPointerAddress(chrData_PTR, { 0x138 });
	*Ptr = basicData.HP;
	Ptr += 0x2;
	*Ptr = basicData.MaxHP;
	Ptr += 0x1;
	*Ptr = basicData.FP;
	Ptr += 0x2;
	*Ptr = basicData.MaxFP;
	Ptr += 0x1;
	*Ptr = basicData.SP;
	Ptr += 0x2;
	*Ptr = basicData.MaxSP;
}

void ChrDataA::SetDebugFlag(DebugFlagState flagState)
{
	Memory_S memory;

	int* Ptr = (int*)memory.GetPointerAddress(chrData_PTR, { DebugFlag0x1 });
	*Ptr = (int)pow(2.0, flagState);
}