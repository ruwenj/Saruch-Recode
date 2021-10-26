#pragma once
#include "Offsets.h"

#include <iostream>


DWORD Offsets1::dwEntityList = NULL;
DWORD Offsets1::m_iHealth = NULL;
DWORD Offsets1::m_iTeamNum = NULL;
DWORD Offsets1::m_iGlowIndex = NULL;
DWORD Offsets1::dwGlowObjectManager = NULL;
DWORD Offsets1::m_lifestate = NULL;
DWORD Offsets1::m_bSpotted = NULL;
DWORD Offsets1::m_szCustomName = NULL;
DWORD Offsets1::m_bDormant = NULL;
DWORD Offsets1::dwLocalPlayer = NULL;
DWORD Offsets1::m_fFlags = NULL;
DWORD Offsets1::m_iShotsFired = NULL;
DWORD Offsets1::dwForceJump = NULL;
DWORD Offsets1::dwForceAttack = NULL;
DWORD Offsets1::m_iCrosshairId = NULL;
DWORD Offsets1::m_flFlashMaxAlpha = NULL;






Offsets1::Offsets1()
{
}


Offsets1::~Offsets1()
{
}

void Offsets1::setOffsets1()
{
	dwEntityList = 0x4DBF78C;
	m_iHealth = 0x100;
	m_iTeamNum = 0xF4;
	m_iGlowIndex = 0x10488;
	dwGlowObjectManager = 0x5307C78;
	m_lifestate = 0x25F;
	m_bSpotted = 0x93D;
	m_szCustomName = 0x304C;
	m_bDormant = 0xED;
	dwLocalPlayer = 0xDA544C;
	m_fFlags = 0x104;
	m_iShotsFired = 0x103E0;
	dwForceJump = 0x52695A0;
	dwForceAttack = 0x31EFD04;
	m_iCrosshairId = 0x11838;
	m_flFlashMaxAlpha = 0x1046C;
	

	std::cout << "Offsets set!" << std::endl;

}