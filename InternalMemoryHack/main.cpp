#include <Windows.h>

void injected_thread() {
	while (true) {
		if (GetAsyncKeyState('M')) {
			// use pointer offset to find the gold address.
			DWORD* player_base = (DWORD*)0x017EED18;
			DWORD* game_base = (DWORD*)(*player_base + 0xA90);
			DWORD* gold = (DWORD*)(*game_base + 4);

			// change gold.
			*gold = 87;
		}

		Sleep(1);
	}
}

BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved) {
	//MessageBox(NULL, L"SUCCESS", L"dll message", 0);

	if (fdwReason == DLL_PROCESS_ATTACH)
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)injected_thread, NULL, 0, NULL);

	return true;
}