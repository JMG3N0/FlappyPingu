#pragma once
#include "raylib.h"
#include <time.h>
#include <cstdlib>

typedef enum GameState { MENU = 0, PLAY, TUTORIAL, CREDITS, EXIT, GAMEOVER } GameState;

const int screenWidth = 750;
const int screenHeight = 450;
const int tubeSpawnDistance = screenWidth / 2;

const float minGapHeight = 60.0f;
const float maxGapHeight = 70.0f;
const float scrollingBackSpeed = 0.1f;
const float scrollingBack2Speed = 20.0f;
const float scrollingBack3Speed = 35.0f;
const float scrollingMidSpeed = 70.0f;
const float scrollingMid2Speed = 85.0f;
const float scrollingForeSpeed = 130.0f;
const float gravity = 650.0f;
const float jumpSpeed = 200.0f;
const float tubeSpeed = 400.0f;



//Texture2D PlayerText = {};
//Texture2D backGround = {};
//Texture2D backGround2 = {};
//Texture2D backGround3 = {};
//Texture2D midGround = {};
//Texture2D midGround2 = {};
//Texture2D foreGround = {};

//void initTextures()
//{
//	PlayerText = LoadTexture("res/player.png");
//	backGround = LoadTexture("res/layers/sky.png");
//	backGround2 = LoadTexture("res/layers/cloud_lonely.png");
//	backGround3 = LoadTexture("res/layers/clouds_bg.png");
//	midGround = LoadTexture("res/layers/glacial_mountains_lightened.png");
//	midGround2 = LoadTexture("res/layers/clouds_mg_2.png");
//	foreGround = LoadTexture("res/layers/clouds_mg_1_lightened.png");
//}
//
//void unloadTextures()
//{
//	UnloadTexture(backGround);
//	UnloadTexture(backGround2);
//	UnloadTexture(backGround3);
//	UnloadTexture(midGround);
//	UnloadTexture(midGround2);
//	UnloadTexture(foreGround);
//	UnloadTexture(PlayerText);
//}



