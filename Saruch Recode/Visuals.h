#pragma once
#include "Entity.h"
#include "LocalPlayer.h"

class Visuals
{
public:
	void do_glow();
	void do_nohands();

private:
	Entity entity_;
	Process process;
	LocalPlayer local;
};

