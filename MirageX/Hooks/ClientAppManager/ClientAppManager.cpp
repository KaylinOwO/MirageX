#include "ClientAppManager.h"

using namespace Hooks;

bool __fastcall ClientAppManager::IsAppDlcInstalled_Hooked(std::uintptr_t a1, DEF_EDX int nGameID, int nDlcID) {
	bool bReturn = IsAppDlcInstalled.fastcall<bool>(a1, EDX nGameID, nDlcID);
	Log("IsAppDlcInstalled: GameID (%i), DlcID (%i), Output (%i)", nGameID, nDlcID, bReturn);
	return (vecAppIDs.empty() || IsInArray(vecAppIDs, nDlcID)) ? true : bReturn;
}

bool __fastcall ClientAppManager::BIsDlcEnabled_Hooked(std::uintptr_t a1, DEF_EDX int nGameID, int nDlcID, std::uintptr_t a4) {
	bool bReturn = BIsDlcEnabled.fastcall<bool>(a1, EDX nGameID, nDlcID, a4);
	Log("BIsDlcEnabled: GameID (%i), DlcID (%i), Output (%i)", nGameID, nDlcID, bReturn);
	return (vecAppIDs.empty() || IsInArray(vecAppIDs, nDlcID)) ? true : bReturn;
}

void ClientAppManager::Setup() {
	AddHook(IsAppDlcInstalled, Interfaces::AppManager[9]);
	AddHook(BIsDlcEnabled, Interfaces::AppManager[11]);
}