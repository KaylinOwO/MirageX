#pragma once
#include "../../Main.h"

namespace Hooks::ClientAppManager {
	inline SafetyHookInline IsAppDlcInstalled,
		BIsDlcEnabled;

	bool __fastcall IsAppDlcInstalled_Hooked(std::uintptr_t a1, DEF_EDX int nAppID, int a3);
	bool __fastcall BIsDlcEnabled_Hooked(std::uintptr_t a1, DEF_EDX int a2, int a3, std::uintptr_t a4);

	void Setup();
}