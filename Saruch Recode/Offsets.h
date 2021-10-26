#pragma once
#include <Windows.h>

#include "Process.h"

class Offsets1
{
public:
	Offsets1();
	~Offsets1();

	void setOffsets1();

	static DWORD dwEntityList;
	static DWORD m_iHealth;
	static DWORD m_iTeamNum;
	static DWORD m_iGlowIndex;
	static DWORD dwGlowObjectManager;
	static DWORD m_lifestate;
	static DWORD m_bSpotted;
	static DWORD m_szCustomName;
	static DWORD m_bDormant;
	static DWORD dwLocalPlayer;
	static DWORD m_fFlags;
	static DWORD m_iShotsFired;
	static DWORD dwForceJump;
	static DWORD dwForceAttack;
	static DWORD m_iCrosshairId;
	static DWORD m_flFlashMaxAlpha;
	
private:
	Process process;
};