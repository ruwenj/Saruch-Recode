#include "Entity.h"


DWORD Entity::getEntityBase(int index)
{
	return process.read<DWORD>(process.clientBase + offsets.dwEntityList + (index * 0x10));
}

int Entity::getEntityHp(DWORD playerbase)
{
	return process.read<int>(playerbase + offsets.m_iHealth);
}

bool Entity::isAlive(DWORD playerbase)
{
	if (getEntityHp(playerbase) > 0 && getEntityHp(playerbase) <= 100)
		return true;
	return false;
}

int Entity::getEntityTeam(DWORD playerbase)
{
	return process.read<int>(playerbase + offsets.m_iTeamNum);
}

int Entity::getGlowIndex(DWORD playerbase)
{
	return process.read<int>(playerbase + offsets.m_iGlowIndex);
}

DWORD Entity::getGlowObject()
{
	return process.read<DWORD>(process.getModuleBase("client.dll") + offsets.dwGlowObjectManager);
}

DWORD Entity::getLifeState(DWORD playerbase)
{
	return process.read<int>(playerbase + offsets.m_lifestate);
}

bool Entity::isValid(DWORD playerbase)
{
	if (Entity::isAlive(playerbase) && Entity::getEntityTeam(playerbase) != 0 && !Entity::isDormant(playerbase) && Entity::getLifeState(playerbase) == 0)
		return true;
	return false;
}

bool Entity::getSpotted(DWORD playerBase)
{
	return process.read<bool>(playerBase + offsets.m_bSpotted);
}

void Entity::setSpotted(DWORD playerBase, bool val)
{
	process.write<bool>(playerBase + offsets.m_bSpotted, val);
}

char* Entity::getEntName(DWORD playerBase)
{
	return process.read<char*>(playerBase + offsets.m_szCustomName);
}

bool Entity::isDormant(DWORD playerBase)
{
	bool dormant = process.read<bool>(playerBase + offsets.m_bDormant);
	if (dormant)
		return true;
	return false;
}

void Entity::glowEsp(DWORD glowObj, int glowInd, float r, float g, float b, float a)
{
	process.write<float>((glowObj + ((glowInd * 0x38) + 0x4)), r);
	process.write<float>((glowObj + ((glowInd * 0x38) + 0x8)), g);
	process.write<float>((glowObj + ((glowInd * 0x38) + 0xC)), b);
	process.write<float>((glowObj + ((glowInd * 0x38) + 0x10)), a);
	process.write<bool>((glowObj + ((glowInd * 0x38) + 0x24)), true);
	process.write<bool>((glowObj + ((glowInd * 0x38) + 0x25)), false);
}