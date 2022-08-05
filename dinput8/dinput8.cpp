#include "GAME.h"

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

	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);

	Memory_S memory_s;

	while (!GetAsyncKeyState(VK_END))
	{

		if (GetAsyncKeyState(VK_NUMPAD5))
		{
			CHR_INS chr_ins;
			list<uintptr_t> myList = chr_ins.GetEntityList(chr_ins.LocalPlayer);

			EntityINS* locPlayer = new EntityINS(myList.front());

			locPlayer->_SpecialEffect->AddSpEffect(1697001);

			delete locPlayer;

			Sleep(500);
		}
		else if (GetAsyncKeyState(VK_NUMPAD3))
		{
			CHR_INS chr_ins;
			list<uintptr_t> myList = chr_ins.GetEntityList(chr_ins.LocalPlayer);

			EntityINS* locPlayer = new EntityINS(myList.front());

			locPlayer->_SpecialEffect->DeleteSpEffect(1697001);

			delete locPlayer;

			Sleep(500);
		}
		else if (GetAsyncKeyState(VK_NUMPAD4))
		{
			CHR_INS chr_ins;

			ChrSpawnerArgs Args;
			Args.NpcParamID = 35100000;
			Args.NpcThinkParamID = 35100000;

			chr_ins._ChrSpawner->CreateCharacter(Args);

			Sleep(500);
		}
		else if (GetAsyncKeyState(VK_NUMPAD2))
		{
			GAME* GAME_PTR_ = new GAME();

			int AreaEntityId = 14000982;
			GAME_PTR_->_Event->_EventCMD->WarpPlayer(14, 0, 0, 0, &AreaEntityId);

			delete GAME_PTR_;

			Sleep(500);
		}

	}

	FreeConsole();

	if (GetAsyncKeyState(VK_END))
		fclose(f);

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