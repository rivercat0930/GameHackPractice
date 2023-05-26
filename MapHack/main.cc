#include <Windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	MessageBox(0, 0, 0, 0);

	if (fdwReason == DLL_PROCESS_ATTACH) {
		DWORD old_protect;
		char hack_code[8] = { 0x90, 0x90, 0x90, 0x83, 0x0E, 0xFF, 0x90, 0x90 };
		unsigned char* hook_location = (unsigned char*)0x006cd519;

		VirtualProtect((void*)hook_location, 8, PAGE_EXECUTE_READWRITE, &old_protect);

		for (int i = 0; i < sizeof(hack_code); i++)
			*(hook_location + i) = hack_code[i];
	}

	return true;
}