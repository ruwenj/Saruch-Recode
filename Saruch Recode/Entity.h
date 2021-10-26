#pragma once
#include "Process.h"
#include "Offsets.h"
#include "LocalPlayer.h"

class Entity
{
public:
	DWORD getEntityBase();
	DWORD getEntityBase(int index);
	int getEntityHp(DWORD playerbase);
	bool isAlive(DWORD playerbase);
	int getEntityTeam(DWORD playerbase);
	int getGlowIndex(DWORD playerbase);
	DWORD getGlowObject();
	DWORD getLifeState(DWORD playerbase);
	bool isValid(DWORD playerbase);
	bool getSpotted(DWORD playerBase);
	void setSpotted(DWORD playerBase, bool val);
	char* getEntName(DWORD playerBase);
	bool isDormant(DWORD playerBase);
	void glowEsp(DWORD glowObj, int glowInd, float r, float g, float b, float a);

private:
	Process process;
	Offsets1 offsets;

};

