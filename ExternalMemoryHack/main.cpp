#include <Windows.h>

int main(int argc, char** argv) {
	HWND wesnoth_window = FindWindow(NULL, L"The Battle for Wesnoth - 1.14.9");

	DWORD process_id = 0;
	GetWindowThreadProcessId(wesnoth_window, &process_id);

	HANDLE wesnoth_process = OpenProcess(PROCESS_ALL_ACCESS, true, process_id);

	SIZE_T gold_value = 0;
	SIZE_T bytes_read = 0;
	ReadProcessMemory(wesnoth_process, (void*)0x017EED18, &gold_value, 4, &bytes_read);

	gold_value = gold_value + 0xa90;
	ReadProcessMemory(wesnoth_process, (void*)gold_value, &gold_value, 4, &bytes_read);

	gold_value = gold_value + 4;

	SIZE_T new_gold_value = 8787940;
	SIZE_T bytes_wirtten = 0;
	WriteProcessMemory(wesnoth_process, (void*)gold_value, &new_gold_value, 4, &bytes_wirtten);

	return 0;
}