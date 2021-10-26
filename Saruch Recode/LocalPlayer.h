#pragma once
#include "Process.h"
#include "Offsets.h"

class LocalPlayer
{
public:
	DWORD getLocalPlayer();
	int getLocalFlags();
	int getLocalHealth();
	int getLocalTeam();
	int getShotsFired();
	void forceJump(int waitTime);
	void forceAttack();
	int getLocalCrossID();
	void setFlashMaxAlpha(float alpha);
	bool isOnGround();

private:
	Process process;
	Offsets1 offsets;
};
