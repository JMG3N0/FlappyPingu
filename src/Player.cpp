#include "Player.h"



void initPlayer(Player& player)
{
	player.PlayerText = LoadTexture("res/player.png"); 
	player.playerSource = { 0,0, static_cast<float>(player.PlayerText.width) / 3,static_cast<float>(player.PlayerText.height) };
	player.initPos = { static_cast<float>(screenWidth) - 600, static_cast<float>(screenHeight) / 2 };
	player.pos = player.initPos;
	player.score = 0;
	player.playerAnimationTime = 0;
	player.alive = true;
	player.collision = false;
}