#include "CHR_INS.h"
#include "ChrSpawner.h"

Signature WorldChrMan = {
	"\x48\x8B\x05\x8B\x54\x82\x03\x48\x85\xC0\x74\x0F\x48\x39\x88\x68\x84\x01\x00\x75\x06\x89\xB1\x5C\x03\x00\x00\x0F\x28\x05\xF8\xF4\x09\x04\x4C\x8D\x45\xE7",
	"xxx????xxxxxxxx????xxxxxxxxxxx????xxxx",
	false
};

//CHR_INS
CHR_INS::CHR_INS()
{
	Memory_S mem;

	uintptr_t SigAddr = mem.GetSignature_BaseAddr(WorldChrMan, { 0x3, 0x7 });
	CHR_INS_BASE = *(uintptr_t*)SigAddr;

	_ChrSpawner = new ChrSpawner(CHR_INS_BASE);
}

CHR_INS::CHR_INS(const CHR_INS& chr_ins)
{

}

CHR_INS::~CHR_INS()
{
	CHR_INS_BASE = NULL;
	delete _ChrSpawner;
}

CHR_INS& CHR_INS::operator=(const CHR_INS& chr_ins)
{
	return *this;
}

//CHR_INS RANDOM STUFF
void CHR_INS::RespawnAllChr()
{
	Memory_S Memory_S;
	int* Val = (int*)Memory_S.GetPointerAddress(CHR_INS_BASE, { 0x18484 });
	*Val = 1;
}

int* CHR_INS::GetMAP_ID()
{
	Memory_S Memory_S;
	int* Val = (int*)Memory_S.GetPointerAddress(CHR_INS_BASE, { _MAP_ID });
	return Val;
}

int* CHR_INS::GetCurrentSessionTime()
{
	Memory_S Memory_S;
	int* Val = (int*)Memory_S.GetPointerAddress(CHR_INS_BASE, { _CurrentSessionTime });
	return Val;
}
//CHR INS ENTITIES/ENTITY LISTS

list<uintptr_t> CHR_INS::GetEntityList(EntityListType entListType)
{
	list<uintptr_t> myList;
	uintptr_t ChrList;
	Memory_S Memory_S;

	if (entListType == EntityListType::LocalPlayer)
	{
		myList.push_back(Memory_S.GetPointerAddress(CHR_INS_BASE, { entListType, 0x0 }));
		return myList;
	}

	ChrList = Memory_S.GetPointerAddress(CHR_INS_BASE, { entListType, 0x0 });
	ChrList = Memory_S.GetPointerAddress(ChrList, { 0x18, 0x0 });

	vector<int> listItemCycle = {0x0, 0x0};

	while (*(uintptr_t*)Memory_S.GetPointerAddress(ChrList, listItemCycle) != NULL)
	{
		myList.push_back(Memory_S.GetPointerAddress(ChrList, listItemCycle));
		listItemCycle[1] += 0x10; //nextItem
	}
	return myList;
}