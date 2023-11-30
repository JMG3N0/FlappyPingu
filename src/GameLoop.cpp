#include "Player.h"
#include "Tube.h"

void initTube(Tube& tube);
void gapRandom(Tube& tube);

GameState PlayGame(bool multiplayer, Player& P1, Player& P2)
{

	Tube T1;
	Tube T2;
	Tube T3;
	initTube(T1);
	initTube(T2);
	initTube(T3);

	/*float scrollingBack = 0.0f;
	float scrollingBack2 = 0.0f;
	float scrollingBack3 = 0.0f;
	float scrollingMid = 0.0f;
	float scrollingMid2 = 0.0f;
	float scrollingFore = 0.0f;*/


	while (!WindowShouldClose())
	{
		if (multiplayer == true)
		{
			if (P1.pos.y > screenHeight || P1.collision) {
				P1.alive = false;
			}
			if (P2.pos.y > screenHeight || P2.collision) {
				P2.alive = false;
			}

			if (P1.alive == false && P2.alive == false)
			{
				
				return GAMEOVER;
			
			}
			
			
		}
		else
		{
			if (P1.pos.y > screenHeight || P1.collision) {
				
				return GAMEOVER;
			}
		}




		if (IsKeyPressed(KEY_SPACE) && P1.pos.y > P1.playerSource.height) {
			P1.pos.y = -jumpSpeed;
		}

		P1.pos.y += gravity * GetFrameTime();

		if (multiplayer == true)
		{
			if (IsKeyPressed(KEY_W) && P2.pos.y > P2.playerSource.height) {
				P2.pos.y = -jumpSpeed;
			}

			P2.pos.y += gravity * GetFrameTime();
		}

		T1.bot.x = T1.top.x -= tubeSpeed * GetFrameTime();
		T2.bot.x = T2.top.x -= tubeSpeed * GetFrameTime();
		T3.bot.x = T3.top.x -= tubeSpeed * GetFrameTime();

		if (T1.top.x + T1.width <= 0) {
			T1.top.x = T1.bot.x = static_cast<float>(GetScreenWidth());
			gapRandom(T1);
			if (multiplayer == true)
			{
				if (P1.alive == true)
				{
					P1.score++;
				}
				if (P2.alive == true)
				{
					P2.score++;
				}
			}
			else
			{
				P1.score++;
			}

		}
		
		if (T2.top.x + T2.width <= 0) {
			T2.top.x = T2.bot.x = static_cast<float>(GetScreenWidth());
			gapRandom(T2);
			if (multiplayer == true)
			{
				if (P1.alive == true)
				{
					P1.score++;
				}
				if (P2.alive == true)
				{
					P2.score++;
				}
			}
			else
			{
				P1.score++;
			}

		}
		
		if (T3.top.x + T3.width <= 0) {
			T3.top.x = T3.bot.x = static_cast<float>(GetScreenWidth());
			gapRandom(T3);
			if (multiplayer == true)
			{
				if (P1.alive == true)
				{
					P1.score++;
				}
				if (P2.alive == true)
				{
					P2.score++;
				}
			}
			else
			{
				P1.score++;
			}

		}

		P1.collision = CheckCollisionRecs(Rectangle{ P1.pos.x, P1.pos.y, P1.playerSource.width, P1.playerSource.height }, T1.top) ||
			CheckCollisionRecs(Rectangle{ P1.pos.x, P1.pos.y, P1.playerSource.width, P1.playerSource.height }, T1.bot) ||
			CheckCollisionRecs(Rectangle{ P1.pos.x, P1.pos.y, P1.playerSource.width, P1.playerSource.height }, T2.top) ||
			CheckCollisionRecs(Rectangle{ P1.pos.x, P1.pos.y, P1.playerSource.width, P1.playerSource.height }, T2.bot) ||
			CheckCollisionRecs(Rectangle{ P1.pos.x, P1.pos.y, P1.playerSource.width, P1.playerSource.height }, T3.top) ||
			CheckCollisionRecs(Rectangle{ P1.pos.x, P1.pos.y, P1.playerSource.width, P1.playerSource.height }, T3.bot);

		if (multiplayer == true)
		{
			P2.collision = CheckCollisionRecs(Rectangle{ P2.pos.x, P2.pos.y, P2.playerSource.width, P2.playerSource.height }, T1.top) ||
				CheckCollisionRecs(Rectangle{ P2.pos.x, P2.pos.y, P2.playerSource.width, P2.playerSource.height }, T1.bot) ||
				CheckCollisionRecs(Rectangle{ P2.pos.x, P2.pos.y, P2.playerSource.width, P2.playerSource.height }, T2.top) ||
				CheckCollisionRecs(Rectangle{ P2.pos.x, P2.pos.y, P2.playerSource.width, P2.playerSource.height }, T2.bot) ||
				CheckCollisionRecs(Rectangle{ P2.pos.x, P2.pos.y, P2.playerSource.width, P2.playerSource.height }, T3.top) ||
				CheckCollisionRecs(Rectangle{ P2.pos.x, P2.pos.y, P2.playerSource.width, P2.playerSource.height }, T3.bot);
		}

		/*scrollingBack -= scrollingBackSpeed * GetFrameTime();
		scrollingBack2 -= scrollingBack2Speed * GetFrameTime();
		scrollingBack3 -= scrollingBack3Speed * GetFrameTime();
		scrollingMid -= scrollingMidSpeed * GetFrameTime();
		scrollingMid2 -= scrollingMid2Speed * GetFrameTime();
		scrollingFore -= scrollingForeSpeed * GetFrameTime();*/


		/*if (scrollingBack <= -backGround.width * 2) scrollingBack = 0;
		if (scrollingBack2 <= -backGround2.width * 2) scrollingBack2 = 0;
		if (scrollingBack3 <= -backGround3.width * 2) scrollingBack3 = 0;
		if (scrollingMid <= -midGround.width * 2) scrollingMid = 0;
		if (scrollingMid2 <= -midGround2.width * 2) scrollingMid2 = 0;
		if (scrollingFore <= -foreGround.width * 2) scrollingFore = 0;*/

		ClearBackground(GetColor(0x052c46ff));

		/*DrawTextureEx(backGround, { scrollingBack , 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(backGround, { backGround.width * 2 + scrollingBack, 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(backGround2, { scrollingBack2 , 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(backGround2, { backGround2.width * 2 + scrollingBack2, 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(backGround3, { scrollingBack3 , 20 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(backGround3, { backGround3.width * 2 + scrollingBack3, 20 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(midGround, { scrollingMid, 40 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(midGround, { midGround.width * 2 + scrollingMid, 40 }, 0.0f, 2.0f, WHITE);

		DrawTextureEx(midGround2, { scrollingMid2, 40 }, 0.0f, 2.0f, WHITE);
		DrawTextureEx(midGround2, { midGround2.width * 2 + scrollingMid2, 40 }, 0.0f, 2.0f, WHITE);*/

		//DrawCircleV(ballPosition, ballRadius, MAROON);
		//DrawRectangle(static_cast<int>(player.width)*2 + 5, static_cast<int>(playerDestination.y - origin.y), static_cast<int>(playerDestination.width), static_cast<int>(playerDestination.height), RED);

		if (multiplayer == true)
		{
			DrawTexturePro(P1.PlayerText, P2.playerSource, Rectangle{P2.pos.x,P2.pos.y, P2.playerSource.width, P2.playerSource.height}, P2.pos, 0, BLUE); //P2
			DrawTexturePro(P1.PlayerText, P1.playerSource, Rectangle{ P1.pos.x,P1.pos.y, P1.playerSource.width, P1.playerSource.height}, P1.pos, 0, RED); //P1
		}
		else
		{
			DrawTexturePro(P1.PlayerText, P1.playerSource, Rectangle{ P1.pos.x,P1.pos.y, P1.playerSource.width, P1.playerSource.height }, P1.pos, 0, WHITE);
		}

		DrawRectangleRec(T1.top, BLUE);
		DrawRectangleRec(T1.bot, BLUE);
		DrawRectangleRec(T2.top, BLUE);
		DrawRectangleRec(T2.bot, BLUE);
		DrawRectangleRec(T3.top, BLUE);
		DrawRectangleRec(T3.bot, BLUE);

		

		//DrawTextureEx(foreGround, { scrollingFore, 50 }, 0.0f, 2.0f, WHITE);
		//DrawTextureEx(foreGround, { foreGround.width * 2 + scrollingFore, 50 }, 0.0f, 2.0f, WHITE);

		DrawText(TextFormat("P1 Score: %i", P1.score), 1, 1, 20, WHITE);
		if (multiplayer == true)
		{
			DrawText(TextFormat("P2 Score: %i", P2.score), 630, 1, 20, WHITE);
		}
		EndDrawing();
	}
	
}