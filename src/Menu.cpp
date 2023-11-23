//#include "Globals.h"
//
//typedef enum GameState {MENU = 0, PLAY, TUTORIAL, CREDITS, EXIT, GAMEOVER} GameState;
//
//void main()
//{
//
//	InitWindow(screenWidth, screenHeight, "FlappyPingu");
//
//	GameState gameState = MENU;
//
//	bool multiplayer = false;
//
//	//float scrollingBack = 0.0f;
//	//float scrollingBack2 = 0.0f;
//	//float scrollingBack3 = 0.0f;
//	//float scrollingMid = 0.0f;
//	//float scrollingMid2 = 0.0f;
//	//float scrollingFore = 0.0f;
//
//	while (!WindowShouldClose())
//	{
//		/*playerAnimationTime += GetFrameTime();
//
//		if (playerAnimationTime > 0.3f)
//		{
//
//			playerSource.x += playerSource.width;
//			if (playerSource.x >= Player.width)
//			{
//				playerSource.x = 0;
//			}
//			playerAnimationTime = 0.0f;
//		}*/
//
//		switch (gameState)
//		{
//		case MENU:
//			if (IsKeyPressed(KEY_P)) {
//				gameState = PLAY;
//			}
//			else if (IsKeyPressed(KEY_C)) {
//				gameState = CREDITS;
//			}
//			else if (IsKeyPressed(KEY_H)) {
//				gameState = TUTORIAL;
//			}
//			else if (IsKeyPressed(KEY_ESCAPE)) {
//				gameState = EXIT;
//			}
//			break;
//		case PLAY:
//
//			break;
//		case TUTORIAL:
//			if (IsKeyPressed(KEY_B)) {
//				gameState = MENU;
//			}
//			break;
//		case CREDITS:
//			if (IsKeyPressed(KEY_B)) {
//				gameState = MENU;
//			}
//			break;
//		case EXIT:
//
//			break;
//		case GAMEOVER:
//
//			break;
//		default:
//			break;
//		}
//	}
//}