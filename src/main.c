#include "game.h"
#include "raylib.h"

int main() {
    /* Init */
    const int screenWidth = 480;
    const int screenHeight = 640;

    InitWindow(screenWidth, screenHeight, "Breakout");

    SetTargetFPS(60);

    Game *game;

    game = InitGame();

    while (!WindowShouldClose()) {
        /* Update */
        if (GetGameState(game) != FINISHED) {
            UpdateGame(game);
        }

        if (GetGameState(game) == FINISHED && IsKeyPressed(KEY_SPACE)) {
            game = RestartGame(game);
        }

        /* Draw */
        BeginDrawing();

        ClearBackground(BLACK);

        DrawGame(game);

        EndDrawing();
    }

    /* DeInit */
    if (game) {
        UnloadGame(game);
    }

    CloseWindow();

    return 0;
}