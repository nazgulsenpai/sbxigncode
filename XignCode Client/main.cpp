#pragma once

#include <Windows.h>
#include <stdio.h>

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{	
		AllocConsole();
		SetConsoleTitle(L"XignCode Client");
		AttachConsole(GetCurrentProcessId());
		::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	
		FILE* pFile = nullptr;
		freopen_s(&pFile, "CON", "r", stdin);
		freopen_s(&pFile, "CON", "w", stdout);
		freopen_s(&pFile, "CON", "w", stderr);
		
		DisableThreadLibraryCalls(hinstDLL);
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
		FreeConsole();
	}

	return TRUE;
}