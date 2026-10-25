#include <stdio.h>
#include "raylib.h"
int main()
{
	InitWindow(500, 800, "Bounce!");
	SetTargetFPS(60);
	Vector2 player = { 250.0f, 25.0f };
	const float speed = 140.0f;  // Pixels per second
    float Yspeed = 0.0;
    const float gravity = 1.5 ;
    const float max_speed = 10.0;
    float badY = 800.0;
    const float badSpeed=0.5;
    bool run = true;
    bool died= false;
    WaitTime(1.0);
	while (!WindowShouldClose() && run)
	{
        player.y += Yspeed;
        Yspeed += gravity;
        float dt = GetFrameTime();
        
        if (IsKeyDown(KEY_RIGHT) && player.x <475 ) player.x += speed * dt;
        if (IsKeyDown(KEY_LEFT) && player.x >25)  player.x -= speed * dt;
        if (IsKeyPressed(KEY_SPACE))  {
            Yspeed = -20; 
            printf("y in now %f. speed in now %f\n", player.y, Yspeed);
        }
        
        // DRAW
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(player, 24.0f, BLUE);
        DrawRectangle(0, badY, 500, 5, RED);
        DrawText("Move with arrow keys; spcce to jump", 20, 20, 20, DARKGRAY);
        EndDrawing(); 
        if (Yspeed >= max_speed) Yspeed = max_speed;
        if (player.y >= badY-25.0 || player.y <=0) {
            run=false;
            died=true;
        }
        badY-=badSpeed;
	}
    if (died) {
        BeginDrawing();
        ClearBackground(RED);
        DrawText("GAME OVER!", 25, 400, 70, DARKGRAY);
        EndDrawing();
        WaitTime(2.0);
    }
    CloseWindow();
    return -1;
}