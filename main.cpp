#include <iostream>
#include <Windows.h>

int main()
{
	//Crée une image virtuel du module en cours exemple Anti-Dumping.exe
	HMODULE moduleBase = GetModuleHandleA(NULL);
	//variable pour l'anciene protection si tu veux la remettre
	DWORD oldProtection;
	//Change la protection de l'image virtual du module https://docs.microsoft.com/en-us/windows/win32/api/memoryapi/nf-memoryapi-virtualprotect
	VirtualProtect((LPVOID)moduleBase, 1000, PAGE_READWRITE, &oldProtection);
	//Efface les headers
	ZeroMemory(moduleBase, 1000);
	VirtualProtect((LPVOID)moduleBase, 1000, oldProtection, &oldProtection);
}
