#include "Player.h"

GameState PlayGame(bool multiplayer, Player& Player1, Player& Player2);
void initPlayer(Player& player);

Texture2D PlayerText = {};
Texture2D backGround = {};
Texture2D backGround2 = {};
Texture2D backGround3 = {};
Texture2D midGround = {};
Texture2D midGround2 = {};
Texture2D foreGround = {};

void menu()
{
	PlayerText = LoadTexture("res/player.png");
	backGround = LoadTexture("res/layers/sky.png");
	backGround2 = LoadTexture("res/layers/cloud_lonely.png");
	backGround3 = LoadTexture("res/layers/clouds_bg.png");
	midGround = LoadTexture("res/layers/glacial_mountains_lightened.png");
	midGround2 = LoadTexture("res/layers/clouds_mg_2.png");
	foreGround = LoadTexture("res/layers/clouds_mg_1_lightened.png");
	InitWindow(screenWidth, screenHeight, "FlappyPingu");

	GameState gameState = MENU;

	Player P1;
	Player P2;
	initPlayer(P1);
	initPlayer(P2);

	Rectangle textureSource = { 0,0, static_cast<float>(PlayerText.width) / 3,static_cast<float>(PlayerText.height) };
	Vector2 texturePosition = { static_cast<float>(screenWidth) - 600, static_cast<float>(screenHeight) / 2 };
	Rectangle textureDestination = { texturePosition.x,texturePosition.y,textureSource.width / 3 * 5, textureSource.height * 5 };

	bool multiplayer = false;

	float textureAnimationTime = 0.0f;
	float scrollingBack = 0.0f;
	float scrollingBack2 = 0.0f;
	float scrollingBack3 = 0.0f;
	float scrollingMid = 0.0f;
	float scrollingMid2 = 0.0f;
	float scrollingFore = 0.0f;

	while (!WindowShouldClose())
	{
		textureAnimationTime += GetFrameTime();

		if (textureAnimationTime > 0.3f)
		{

			textureSource.x += textureSource.width;
			if (textureSource.x >= PlayerText.width)
			{
				textureSource.x = 0;
			}
			textureAnimationTime = 0.0f;
		}

		switch (gameState) 
		{
		case MENU:
			if (IsKeyPressed(KEY_P)) {
				gameState = PLAY;
			}
			else if (IsKeyPressed(KEY_C)) {
				gameState = CREDITS;
			}
			else if (IsKeyPressed(KEY_H)) {
				gameState = TUTORIAL;
			}
			else if (IsKeyPressed(KEY_ESCAPE)) {
				gameState = EXIT;
			}
			break;
		case PLAY:
			if (IsKeyPressed(KEY_KP_1))
			{
				multiplayer = false;
			}
			if (IsKeyPressed(KEY_KP_2))
			{
				multiplayer = true;
			}
			if (IsKeyPressed(KEY_ENTER))
			{
				gameState = PlayGame(multiplayer, P1, P2);
			}
			break;
		case TUTORIAL:
			if (IsKeyPressed(KEY_B)) {
				gameState = MENU;
			}
			break;
		case CREDITS:
			if (IsKeyPressed(KEY_B)) {
				gameState = MENU;
			}
			break;
		case EXIT:
			UnloadTexture(backGround);
			UnloadTexture(backGround2);
			UnloadTexture(backGround3);
			UnloadTexture(midGround);
			UnloadTexture(midGround2);
			UnloadTexture(foreGround);
			UnloadTexture(PlayerText);
			CloseWindow();
			break;
		case GAMEOVER:
			P1.pos = P1.initPos;
			P1.collision = false;
			P1.alive = true;
			P1.score = 0;

			if (multiplayer == true)
			{
				P2.pos = P2.initPos;
				P2.collision = false;
				P2.alive = true;
				P2.score = 0;
			}
			if (IsKeyDown(KEY_R))
			{
				P1.pos = P1.initPos;
				P1.collision = false;
				P1.alive = true;
				P1.score = 0;
				gameState = PLAY;
			}

			if (IsKeyDown(KEY_B)) {

				multiplayer = false;
				P1.score = 0;
				P2.score = 0;
				gameState = MENU;
			}
			break;
		default:
			break;
		}
		scrollingBack -= scrollingBackSpeed * GetFrameTime();
		scrollingBack2 -= scrollingBack2Speed * GetFrameTime();
		scrollingBack3 -= scrollingBack3Speed * GetFrameTime();
		scrollingMid -= scrollingMidSpeed * GetFrameTime();
		scrollingMid2 -= scrollingMid2Speed * GetFrameTime();
		scrollingFore -= scrollingForeSpeed * GetFrameTime();


		if (scrollingBack <= -backGround.width * 2) scrollingBack = 0;
		if (scrollingBack2 <= -backGround2.width * 2) scrollingBack2 = 0;
		if (scrollingBack3 <= -backGround3.width * 2) scrollingBack3 = 0;
		if (scrollingMid <= -midGround.width * 2) scrollingMid = 0;
		if (scrollingMid2 <= -midGround2.width * 2) scrollingMid2 = 0;
		if (scrollingFore <= -foreGround.width * 2) scrollingFore = 0;

		BeginDrawing();
		ClearBackground(GetColor(0x052c46ff));

		DrawTextureEx(backGround, { scrollingBack , 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(backGround, { backGround.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(backGround2, { scrollingBack2 , 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(backGround2, { backGround2.width * 2 + scrollingBack2, 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(backGround3, { scrollingBack3 , 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(backGround3, { backGround3.width * 2 + scrollingBack3, 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(midGround, { scrollingMid, 40 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(midGround, { midGround.width * 2 + scrollingMid, 40 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(midGround2, { scrollingMid2, 40 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(midGround2, { midGround2.width * 2 + scrollingMid2, 40 }, 0.0f, 2.0f, WHITE);

		if (multiplayer == true)
		{
			DrawTexturePro(PlayerText, textureSource, textureDestination, texturePosition, 0, BLUE);
		}
		else
		{
			DrawTexturePro(PlayerText, textureSource, textureDestination, texturePosition, 0, WHITE);
		}
		DrawTextureEx(foreGround, { scrollingFore, 50 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(foreGround, { foreGround.width * 2 + scrollingFore, 50 }, 0.0f, 2.0f, WHITE);

		switch (gameState)
		{
		case MENU:
			DrawText("Press P to Play", screenWidth / 2 - 70, screenHeight / 2 - 20, 20, WHITE);
			DrawText("Press C for Credits", screenWidth / 2 - 90, screenHeight / 2 + 20, 20, WHITE);
			DrawText("Press H for How To Play", screenWidth / 2 - 110, screenHeight / 2 + 60, 20, WHITE);
			DrawText("Press ESC to Exit", screenWidth / 2 - 80, screenHeight / 2 + 100, 20, WHITE);

			DrawText("Version 1.0 Flappy_Pingu", 10, 435, 15, BLACK);

			DrawText("Flappy Pingu", screenWidth / 2 - 120, screenHeight / 2 - 80, 40, WHITE);
			break;

		case PLAY:
			DrawText("How many people are playing ?", screenWidth / 2 - 150, screenHeight / 2 - 20, 20, WHITE);
			DrawText("Press the number in the Keypad", screenWidth / 2 - 150, screenHeight / 2 + 20, 20, WHITE);
			if (multiplayer == false)
			{
				DrawText("Currently: 1", screenWidth / 2 - 150, screenHeight / 2 + 60, 20, WHITE);
			}
			else
			{
				DrawText("Currently: 2", screenWidth / 2 - 150, screenHeight / 2 + 60, 20, WHITE);
			}
			DrawText("Player 1 is Red - Player 2 is Blue", screenWidth / 2 - 150, screenHeight / 2 + 100, 20, WHITE);
			DrawText("Press Enter when you are done selecting...", screenWidth / 2 - 150, screenHeight / 2 + 140, 20, WHITE);
			break;
		case CREDITS:
			DrawText("Game Code by Tupac Sierra", screenWidth / 2 - 100, screenHeight / 2 - 20, 20, WHITE);
			DrawText("Game Code by Joan Manuel Rivas", screenWidth / 2 - 100, screenHeight / 2 + 20, 20, WHITE);
			DrawText("Art background by @vnitti_art ", screenWidth / 2 - 125, screenHeight / 2 + 60, 20, WHITE);
			DrawText("Press B to go back to the main menu.", screenWidth / 2 - 160, screenHeight / 2 + 100, 20, WHITE);
			break;

		case TUTORIAL:
			DrawText("How To Play", screenWidth / 2 - 70, screenHeight / 2 - 80, 30, WHITE);
			DrawText("Player 1 press SPACE to make the penguin fly", screenWidth / 2 - 150, screenHeight / 2 - 20, 20, WHITE);
			DrawText("Player 2 press W to make the penguin fly", screenWidth / 2 - 150, screenHeight / 2 + 20, 20, WHITE);
			DrawText("Avoid the pipes and try to stay alive!", screenWidth / 2 - 150, screenHeight / 2 + 60, 20, WHITE);
			DrawText("Press B to go back to the main menu.", screenWidth / 2 - 150, screenHeight / 2 + 100, 20, WHITE);

			break;
		}
		EndDrawing();
	}
	UnloadTexture(backGround);
	UnloadTexture(backGround2);
	UnloadTexture(backGround3);
	UnloadTexture(midGround);
	UnloadTexture(midGround2);
	UnloadTexture(foreGround);
	UnloadTexture(PlayerText);
	CloseWindow();
}