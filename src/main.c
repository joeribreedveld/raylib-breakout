#include "paddle.h"
#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 480;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Breakout");

    SetTargetFPS(60);

    Paddle *paddle = InitPaddle();

    while (!WindowShouldClose()) {
        /* Update */
        UpdatePaddle(paddle);

        /* Draw */
        BeginDrawing();

        ClearBackground(BLACK);

        DrawPaddle(paddle);

        EndDrawing();
    }

    /* DeInit */
    UnloadPaddle(paddle);

    CloseWindow();

    return 0;
}