#include <Windows.h>
#include <iostream>

#include "Offsets.h"
#include "Entity.h"
#include "Visuals.h"
#include "Misc.h"

Misc misc;
Process process;
Offsets1 offsets;
Entity entity;
Visuals visual;





int main()
{
	SetConsoleTitleA("da hookt nix brudi");
	while (!process.start())
	{
		system("cls");
		std::cout << "Warten auf CSGO . . . " << std::endl;
		Sleep(500);
	}

	system("cls");
	std::cout << "CSGO izz daa!" << std::endl;
	Sleep(500);
	system("cls");
	//config.load();
	offsets.setOffsets1();

	Beep(1000, 300);
	std::cout << "Mogelmodul aktiviert ^^" << std::endl;
	while(true)
	{
		//visual.do_glow();
		misc.do_bhop();
		visual.do_nohands();
	}

return 1;
}
