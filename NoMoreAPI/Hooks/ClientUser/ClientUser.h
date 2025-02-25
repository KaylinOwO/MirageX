#pragma once
#include "../../Main.h"

namespace Hooks::ClientUser {
	inline SafetyHookInline IsUserSubscribedAppInTicket,
		BIsSubscribedApp,
		GetSubscribedApps;

	int __fastcall IsUserSubscribedAppInTicket_Hooked(std::uintptr_t a1, DEF_EDX std::uint64_t nSteamID, int nAppID);
	bool __fastcall BIsSubscribedApp_Hooked(std::uintptr_t a1, DEF_EDX int nAppID);
	void __fastcall GetSubscribedApps_Hooked(std::uintptr_t a1, DEF_EDX std::uint32_t* arrAppIDs, std::uint32_t nArrSize, bool a3);

	void Setup();
}