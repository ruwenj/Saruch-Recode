#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

using namespace std;

class Process
{
public:
	Process();
	~Process();

	bool start();
	int getProcessID(string processName);
	DWORD getModuleBase(string module);
	DWORD getModuleSize(string module);

	DWORD scanPattern(DWORD base, DWORD size, BYTE* sign, char* mask);

	static HANDLE hProcess;
	static DWORD clientBase;
	static DWORD clientSize;
	static DWORD PID;

	template <class T> T read(DWORD address)
	{
		T buffer;
		ReadProcessMemory(hProcess, (LPVOID)address, &buffer, sizeof(buffer), NULL);
		return buffer;
	}

	template <class T> void write(DWORD address, T value)
	{
		WriteProcessMemory(hProcess, (LPVOID)address, &value, sizeof(value), NULL);
	}

private:
#define TARGET_PROCESS "csgo.exe"
#define MODULE_CLIENT "client.dll"

};

