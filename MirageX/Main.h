#pragma once

#include <windows.h>     
#include <psapi.h>    
#include <string>
#include <string_view>   
#include <vector>        
#include <cstdlib>       
#include <cstdint>    
#include <sstream>
#include <fstream>

#include "Dependencies/SafetyHook/safetyhook.hpp"
#include "Dependencies/silver-bun.h"

#if defined(_M_X64)
#define DEF_EDX
#define EDX
#define STEAMCLIENT "steamclient64.dll"
#else
#define DEF_EDX void* edx,
#define EDX edx,
#define STEAMCLIENT "steamclient.dll"
#endif

#define AddHook(hook, addr) hook = safetyhook::create_inline(addr, ##hook##_Hooked);
#define IsInArray(arr, val) (std::find((arr).begin(), (arr).end(), (val)) != (arr).end())

#include "Interfaces/Interfaces.h"
#include "Hooks/Hooks.h"

template <typename... Args>
void Log(const char* pszFormat, Args&&... nArgs) {
#ifdef _DEBUG
	static std::ofstream ofsLogFile("MirageX.log", std::ios_base::app);
	if (!ofsLogFile) return;

	char chBuffer[1024];
	snprintf(chBuffer, sizeof(chBuffer), pszFormat, nArgs...);

	ofsLogFile << chBuffer << std::endl;
	ofsLogFile.flush();
#endif
}

inline std::vector<int> vecAppIDs = {};
inline void AppIDs() {
	std::ifstream ifsFile("AppIDs.txt");
	if (!ifsFile) return;

	std::string strLine;

	while (std::getline(ifsFile, strLine)) {
		if (auto iCommentPos = strLine.find(';'); iCommentPos != std::string::npos)
			strLine.erase(iCommentPos);

		size_t iStart = 0;
		while (iStart < strLine.size()) {
			int nAppID = std::strtol(strLine.data() + iStart, nullptr, 10);
			vecAppIDs.push_back(nAppID);
			Log("Registered AppID: %i", nAppID);
			iStart = strLine.find(',', iStart) + 1;
			if (iStart == 0) break;
		}
	}
}
