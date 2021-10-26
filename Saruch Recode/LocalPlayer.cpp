#include "LocalPlayer.h"

DWORD LocalPlayer::getLocalPlayer()
{
	return process.read<DWORD>(process.clientBase + offsets.dwLocalPlayer);
}

int LocalPlayer::getLocalFlags()
{
	return process.read<int>(getLocalPlayer() + offsets.m_fFlags);
}

int LocalPlayer::getLocalHealth()
{
	return process.read<int>(getLocalPlayer() + offsets.m_iHealth);
}

int LocalPlayer::getLocalTeam()
{
	return process.read<int>(getLocalPlayer() + offsets.m_iTeamNum);
}

int LocalPlayer::getShotsFired()
{
	return process.read<int>(getLocalPlayer() + offsets.m_iShotsFired);
}

void LocalPlayer::forceJump(int waitTime)
{
	process.write<int>(process.clientBase + offsets.dwForceJump, 1);
	Sleep(waitTime);
	process.write<int>(process.clientBase + offsets.dwForceJump, 0);
}

void LocalPlayer::forceAttack()
{
	process.write<int>(process.clientBase + offsets.dwForceAttack, 5);
	Sleep(50);
	process.write<int>(process.clientBase + offsets.dwForceAttack, 4);
}

int LocalPlayer::getLocalCrossID()
{
	return process.read<int>(getLocalPlayer() + offsets.m_iCrosshairId);
}

void LocalPlayer::setFlashMaxAlpha(float alpha)
{
	process.write<float>(getLocalPlayer() + offsets.m_flFlashMaxAlpha, alpha);
}

bool LocalPlayer::isOnGround()
{
	if (getLocalFlags() & 0x1)
		return true;
	else
		return false;
}