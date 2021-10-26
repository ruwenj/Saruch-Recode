#pragma once
#include "Process.h"
#include "LocalPlayer.h"
#include "Offsets.h"

class Misc
{
public:
	Misc();
	~Misc();
	void do_bhop();

private:
	Process process;
	Offsets1 offsets;
	LocalPlayer localplayer;
};

