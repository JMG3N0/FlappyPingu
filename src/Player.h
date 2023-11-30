#pragma once
#include "Globals.h"



struct Player
{
	Texture2D PlayerText;
	Rectangle playerSource;
	Vector2 initPos;
	Vector2 pos;
	int score;
	float playerAnimationTime;
	bool alive;
	bool collision;
};
