#include "pch.h"
#include "Aeyth8/Proxy.hpp"
#include "Aeyth8/Pointers.hpp"
#include "Aeyth8/Hooks/Hooks.hpp"
#include "Aeyth8/Hooks/UFunctions.hpp"



static void Init()
{
	GBA = (uintptr_t)GetModuleHandleA(0);

	LogWin();

	Hooks::Init();
	Hooks::CreateAndEnableHook((GBA + 0x3CC5010), UFunctions::Func::UConsole, &UFunctions::Decl::FC_UConsole, "UConsole");
	Hooks::CreateAndEnableHook((GBA + 0x3C77230), UFunctions::Func::Browse, &UFunctions::Decl::FC_Browse, "Browse");

	if (!(!CheckNull(UWorld()) && !CheckNull(Player0()))) Sleep(10000);

	LogA("INITIALIZED", "The Global Base Address [GBA] is " + HexToString(GBA));

	// Allocates local pointers
	Engine = UEngine(); World = UWorld(); KismetSys = UKismetSys();

	if (!Global::bConstructedUConsole) { Global::bConstructedUConsole = true;
		ConstructUConsole();
		LogA("Browse", "Constructing UConsole.");
	}



}











int __stdcall DllMain(HMODULE hModule, DWORD ulReasonForCall, LPVOID lpReserved) {
	DisableThreadLibraryCalls(hModule);

	if (ulReasonForCall != DLL_PROCESS_ATTACH)
		return 1;

	Proxy::Attach(hModule);

	return 1;
}