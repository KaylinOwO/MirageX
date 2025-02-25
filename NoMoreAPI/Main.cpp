#include "Main.h"


DWORD APIENTRY ModThread(LPVOID lpParam) {
	AppIDs();

	Interfaces::Setup();
	Hooks::Setup();

	return 0;
}

bool WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
		if (const HANDLE hMain = CreateThread(0, 0, ModThread, hinstDLL, 0, 0))
			CloseHandle(hMain);

	return TRUE;
}
