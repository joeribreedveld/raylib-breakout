#include "game.h"
#include "paddle.h"
#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 480;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Breakout");

    SetTargetFPS(60);

    Game *game = InitGame();

    while (!WindowShouldClose()) {
        /* Update */
        UpdateGame(game);

        /* Draw */
        BeginDrawing();

        ClearBackground(BLACK);

        DrawGame(game);

        EndDrawing();
    }

    /* DeInit */
    UnloadGame(game);

    CloseWindow();

    return 0;
}