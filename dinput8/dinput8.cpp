#include "Auto-ReviveMod/Auto-Revive.h"

HINSTANCE mHinst = 0, mHinstDLL = 0;

extern "C" uintptr_t mProcs[6] = { 0 };

LPCSTR mImportNames[6] = {

	"DirectInput8Create",
	"GetdfDIJoystick",
	"DllCanUnloadNow",
	"DllGetClassObject",
	"DllRegisterServer",
	"DllUnregisterServer",

};

void Begin(HINSTANCE hinstDLL) {

	char dllpath[MAX_PATH];
	GetSystemDirectory(dllpath, MAX_PATH);
	strcat_s(dllpath, "\\dinput8.dll");
	mHinstDLL = LoadLibrary(dllpath);
	if (!mHinstDLL) {
		MessageBoxA(NULL, "Failed to load original DLL", "Error", MB_ICONERROR);
		return;
	};

	for (int i = 0; i < 6; i++)
		mProcs[i] = (uintptr_t)GetProcAddress(mHinstDLL, mImportNames[i]);

	Auto_Revive_Main();
	/*
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	Auto_Revive_Main();

	FreeConsole();
	
	if (GetAsyncKeyState(VK_END))
		fclose(f);
		*/
	//FreeLibraryAndExitThread(hModule, 0);

	return;
};

BOOL WINAPI DllMain(HMODULE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

	switch (fdwReason) {
	case (DLL_PROCESS_ATTACH): {
		DisableThreadLibraryCalls(hinstDLL);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Begin, hinstDLL, 0, 0);
		break;
	};
	case(DLL_PROCESS_DETACH): {

		FreeLibrary(mHinstDLL);

		break;
	};
	}

	return 1;
}

extern "C" void _DirectInput8Create();