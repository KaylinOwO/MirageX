#include "ClientUser.h"

using namespace Hooks;

int __fastcall ClientUser::IsUserSubscribedAppInTicket_Hooked(std::uintptr_t a1, DEF_EDX std::uint64_t nSteamID, int nAppID) {
	int nReturn = IsUserSubscribedAppInTicket.fastcall<bool>(a1, EDX nSteamID, nAppID);
	Log("IsUserSubscribedAppInTicket: SteamID (%i), AppID (%i), Output (%i)", nSteamID, nAppID, nReturn);
	return (vecAppIDs.empty() || IsInArray(vecAppIDs, nAppID)) ? 0 /* User has a license for specified app */ : nReturn;
}

bool __fastcall ClientUser::BIsSubscribedApp_Hooked(std::uintptr_t a1, DEF_EDX int nAppID) {
	bool bReturn = BIsSubscribedApp.fastcall<bool>(a1, EDX nAppID);
	Log("BIsSubscribedApp: nAppID (%i), Output (%i)", nAppID, bReturn);
	return (vecAppIDs.empty() || IsInArray(vecAppIDs, nAppID)) ? true : bReturn;
}

void __fastcall ClientUser::GetSubscribedApps_Hooked(std::uintptr_t a1, DEF_EDX std::uint32_t* arrAppIDs, std::uint32_t nArrSize, bool a3) {
	GetSubscribedApps.fastcall<void>(a1, EDX arrAppIDs, nArrSize, a3);

	for (std::uint32_t i = 0; i < nArrSize; i++)
		Log("GetSubscribedApps: nAppID (%i)", arrAppIDs[i]);

	for (const auto& nCustom : vecAppIDs) {
		for (std::uint32_t i = 0; i < nArrSize; i++) {
			if (arrAppIDs[i] <= 0) {
				arrAppIDs[i] = nCustom;
				break;
			}
		}
	}
}

void ClientUser::Setup() {
	AddHook(IsUserSubscribedAppInTicket, Interfaces::ClientUser[120]);
	AddHook(BIsSubscribedApp, Interfaces::ClientUser[184]);
	AddHook(GetSubscribedApps, Interfaces::ClientUser[185]);
}