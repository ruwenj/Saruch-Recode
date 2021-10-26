#include "Visuals.h"

#include <iostream>


void Visuals::do_glow()
{
	for (int i = 0; i < 32; i++)
	{
		/*std::cout << "Entity Base: " << entity_.getEntityBase(i) << std::endl;
		std::cout << "Entity Team: " << entity_.getEntityTeam(i) << std::endl;
		std::cout << "Local Team: " << local.getLocalTeam() << std::endl;*/
		
		if (entity_.getEntityTeam(i) != local.getLocalTeam())
		{
			//std::cout << entity_.isValid(entity_.getEntityBase(i)) << std::endl;
			//std::cout << "Ok hallo2" << std::endl;
			if (entity_.getEntityHp(entity_.getEntityBase(i)) >= 70)
			{
				std::cout << "Ueber 70 hp" << std::endl;
				entity_.glowEsp(entity_.getGlowObject(), entity_.getGlowIndex(entity_.getEntityBase(i)), 0, 255, 0, 255);
			}
			else if (entity_.getEntityHp(entity_.getEntityBase(i)) > 35 && entity_.getEntityHp(entity_.getEntityBase(i)) < 70)
			{
				std::cout << "Ueber 35 hp" << std::endl;
				entity_.glowEsp(entity_.getGlowObject(), entity_.getGlowIndex(entity_.getEntityBase(i)), 255, 255, 0, 255);
			}
			else
			{
				std::cout << "Unter 35 hp" << std::endl;
				entity_.glowEsp(entity_.getGlowObject(), entity_.getGlowIndex(entity_.getEntityBase(i)), 255, 0, 0, 255);
			}
		}
	}
	
}


void Visuals::do_nohands()
{
	process.write<float>(local.getLocalPlayer() + Offsets1::m_flFlashMaxAlpha, 0.f);
}