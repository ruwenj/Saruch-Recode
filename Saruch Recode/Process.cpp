#include "Process.h"

HANDLE Process::hProcess = NULL;
DWORD Process::clientBase = NULL;
DWORD Process::clientSize = NULL;
DWORD Process::PID = NULL;


Process::Process()
{
}


Process::~Process()
{
}

bool Process::start()
{
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, getProcessID(TARGET_PROCESS));
	clientBase = getModuleBase(MODULE_CLIENT);
	clientSize = getModuleSize(MODULE_CLIENT);
	PID = getProcessID(TARGET_PROCESS);

	if (hProcess == NULL || clientBase == NULL)
		return false;

	return true;
}

int Process::getProcessID(string processName)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(hSnapshot, &entry))
	{
		do
		{
			if (!_stricmp(entry.szExeFile, processName.c_str()))
				return entry.th32ProcessID;
		} while (Process32Next(hSnapshot, &entry));
	}
	CloseHandle(hSnapshot);
	return NULL;
}

DWORD Process::getModuleBase(string processName)
{
	MODULEENTRY32 entry;
	entry.dwSize = sizeof(MODULEENTRY32);
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, getProcessID(TARGET_PROCESS));

	if (Module32First(hSnap, &entry) != TRUE) return NULL;

	do
	{
		if (!strcmp(entry.szModule, processName.c_str()))
			return (DWORD)entry.modBaseAddr;
	} while (Module32Next(hSnap, &entry) == TRUE);

	CloseHandle(hSnap);

	return NULL;
}

DWORD Process::getModuleSize(string processName)
{
	MODULEENTRY32 entry;
	entry.dwSize = sizeof(MODULEENTRY32);
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, getProcessID(TARGET_PROCESS));

	if (Module32First(hSnap, &entry) != TRUE) return NULL;

	do
	{
		if (!strcmp(entry.szModule, processName.c_str()))
			return (DWORD)entry.modBaseSize;
	} while (Module32Next(hSnap, &entry) == TRUE);

	CloseHandle(hSnap);

	return NULL;
}

bool bDataCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	return (*szMask) == NULL;
}

DWORD Process::scanPattern(DWORD base, DWORD size, BYTE* sign, char* mask)
{
	MEMORY_BASIC_INFORMATION mbi = { 0 };
	DWORD offset = 0;
	while (offset < size)
	{
		VirtualQueryEx(hProcess, (LPCVOID)(base + offset), &mbi, sizeof(MEMORY_BASIC_INFORMATION));
		if (mbi.State != MEM_FREE)
		{
			BYTE* buffer = new BYTE[mbi.RegionSize];
			ReadProcessMemory(hProcess, mbi.BaseAddress, buffer, mbi.RegionSize, NULL);
			for (size_t i = 0; i < mbi.RegionSize; i++)
			{
				if (bDataCompare(buffer + i, sign, mask))
				{
					delete[] buffer;
					return (DWORD)mbi.BaseAddress + i;
				}
			}

			delete[] buffer;
		}
		offset += mbi.RegionSize;
	}
	return NULL;
}