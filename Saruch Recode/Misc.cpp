#include "Misc.h"

#include <iostream>

Misc::Misc()
{
}

Misc::~Misc()
{
}

void Misc::do_bhop()
{
	if (localplayer.isOnGround() == true)
	{
		std::cout << localplayer.isOnGround() << std::endl;
		if (GetAsyncKeyState(VK_SPACE))
		{
			std::cout << "Key pressed" << std::endl;
			process.write<DWORD>(process.clientBase + offsets.dwForceJump, 5);
		}
	}
	else
	{
		std::cout << localplayer.isOnGround() << std::endl;
		process.write<DWORD>(process.clientBase + offsets.dwForceJump, 4);
	}
}