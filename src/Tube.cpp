#include "Tube.h"

void gapRandom(Tube& tube)
{
	do
	{
		tube.height = rand() % 35;
	} while (tube.height * 2 > maxGapHeight || tube.height * 2 < minGapHeight);
}

void initTube(Tube& tube)
{	
	tube.width = 95;
	gapRandom(tube);
	tube.top = {static_cast<float>(screenWidth), 0, static_cast<float>(tube.width), static_cast<float>(tube.height)};
	tube.bot = { static_cast<float>(screenWidth), static_cast<float>(screenHeight)-tube.height,  static_cast<float>(tube.width), static_cast<float>(tube.height) };
	
}

