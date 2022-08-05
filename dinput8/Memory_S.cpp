#include "Memory_S.h"

uintptr_t Memory_S::SetBaseAddr(int Offset)
{
	uintptr_t OffsetEx = Memory_S::moduleBase + Offset;
	return OffsetEx;
}
uintptr_t Memory_S::GetPointerAddress(uintptr_t PTR, vector<int> offsets)
{
	uintptr_t addr = PTR;

	addr += offsets[0];

	for (int i = 1; i < offsets.size(); i++)
	{	
		addr = *(uintptr_t*)addr;
		addr += offsets[i];
	}

	return addr;
}
uintptr_t Memory_S::GetModuleBase()
{
	return moduleBase;
}

Memory_S::Memory_S()
{
	hHandle = GetModuleHandle("eldenring.exe");

	if (hHandle) {
		MEMORY_BASIC_INFORMATION sInfo;
		VirtualQuery(hHandle, &sInfo, sizeof(sInfo));
		IMAGE_DOS_HEADER* hDos = (IMAGE_DOS_HEADER*)hHandle;
		IMAGE_NT_HEADERS* hPe = (IMAGE_NT_HEADERS*)((ULONG64)sInfo.AllocationBase + (ULONG64)hDos->e_lfanew);
		moduleBase = (uint64_t)hHandle;
		moduleEnd = moduleBase + (uint64_t)hPe->OptionalHeader.SizeOfImage;
		CloseHandle(hHandle);
	};
}

Memory_S::~Memory_S()
{

}

uintptr_t Memory_S::GetSignature(Signature _Signature)
{
	DWORD64 SpeedUp;

	size_t SigSize = strlen(_Signature.Mask);

	for (DWORD64 i = moduleBase; i < moduleEnd - SigSize; i++)
	{
		if (_Signature.isFunctionSignature) //speeds up scan when scanning for function call addresses
		{
			SpeedUp = 0;
			SpeedUp = i % 0x10;

			if (SpeedUp != 0)
			{
				SpeedUp = 0x10 - SpeedUp;
				i += (SpeedUp - 1);
				continue;
			}
		}

		for (BYTE j = 0; j < SigSize; j++)
		{
			if (_Signature.Mask[j] == 'x' && (BYTE)_Signature.Array[j] != *(BYTE*)(i + j))
				break;

			if(j == SigSize - 1)
				return (uintptr_t)i;
		}
	}
	return 0;
}

uintptr_t Memory_S::GetSignature_BaseAddr(Signature _Signature, vector<int> Offset)
{
	uintptr_t SigAddr = GetSignature(_Signature);

	SigAddr += ((*(int*)(SigAddr + Offset[0])) + Offset[1]);

	return SigAddr;
}

void Memory_S::Callx64Function(uintptr_t funcAddr, uintptr_t PTR)
{
	void(*FuncCall)(...);
	*(uintptr_t*)&FuncCall = funcAddr;
	FuncCall(PTR);
}

void Memory_S::Callx64Function(uintptr_t funcAddr, uintptr_t PTR, int ARG1)
{
	void(*FuncCall)(...);
	*(uintptr_t*)&FuncCall = funcAddr;
	FuncCall(PTR, ARG1);
}

void Memory_S::Callx64Function(uintptr_t funcAddr, uintptr_t PTR, int* ARG1, bool ARG2)
{
	void(*FuncCall)(...);
	*(uintptr_t*)&FuncCall = funcAddr;
	FuncCall(PTR, ARG1, ARG2);
}

void Memory_S::Callx64Function(uintptr_t funcAddr, int ARG1, int ARG2, int ARG3, int ARG4, int* ARG5)
{
	void(*FuncCall)(...);
	*(uintptr_t*)&FuncCall = funcAddr;
	FuncCall(ARG1, ARG2, ARG3, ARG4, ARG5);
}

void Memory_S::Callx64Function(uintptr_t funcAddr, int ARG1, int ARG2, int ARG3, int ARG4, int ARG5)
{
	void(*FuncCall)(...);
	*(uintptr_t*)&FuncCall = funcAddr;
	FuncCall(ARG1, ARG2, ARG3, ARG4, ARG5);
}

void Memory_S::Callx64Function(uintptr_t funcAddr, bool ARG1)
{
	void(*FuncCall)(...);
	*(uintptr_t*)&FuncCall = funcAddr;
	FuncCall(ARG1);
}

void Memory_S::Callx64Function(uintptr_t funcAddr, int ARG1)
{
	void(*FuncCall)(...);
	*(uintptr_t*)&FuncCall = funcAddr;
	FuncCall(ARG1);
}