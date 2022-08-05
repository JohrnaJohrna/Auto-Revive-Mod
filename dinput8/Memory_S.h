#pragma once

#include "main.h"

struct Signature {
	LPCSTR Array;
	LPCSTR Mask;
	bool isFunctionSignature;
};

class Memory_S
{
private:
	HANDLE hHandle;
	uintptr_t moduleBase;
	uintptr_t moduleEnd;
public:
	Memory_S();
	~Memory_S();
	uintptr_t GetModuleBase();
	uintptr_t SetBaseAddr(int Offset);
	uintptr_t GetPointerAddress(uintptr_t PTR, vector<int> offsets);
	uintptr_t GetSignature(Signature _Signature);
	uintptr_t GetSignature_BaseAddr(Signature _Signature, vector<int> Offset);
	void Callx64Function(uintptr_t funcAddr, uintptr_t PTR);
	void Callx64Function(uintptr_t funcAddr, uintptr_t PTR, int ARG1);
	void Callx64Function(uintptr_t funcAddr, uintptr_t PTR, int* ARG1, bool ARG2);
	void Callx64Function(uintptr_t funcAddr, int ARG1, int ARG2, int ARG3, int ARG4, int* ARG5);
	void Callx64Function(uintptr_t funcAddr, int ARG1, int ARG2, int ARG3, int ARG4, int ARG5);
	void Callx64Function(uintptr_t funcAddr, bool ARG1);
	void Callx64Function(uintptr_t funcAddr, int ARG1);
};