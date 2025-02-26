#include "Interfaces.h"

void Interfaces::Setup() {
	HMODULE hClient = nullptr;
	while (!(hClient = GetModuleHandle(STEAMCLIENT)))
		Sleep(5);

	CModule nModule = CModule(reinterpret_cast<std::uintptr_t>(hClient));
	AppManager = nModule.GetVirtualMethodTable(".?AVIClientAppManagerMap@@").RCast<void**>();
	ClientUser = nModule.GetVirtualMethodTable(".?AVIClientUserMap@@").RCast<void**>();
}