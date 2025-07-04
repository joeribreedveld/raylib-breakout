#include "game.h"

#include <stdlib.h>

#include "brick.h"

Game *InitGame() {
    Game *game = malloc(sizeof(Game));

    game->paddle = InitPaddle();
    game->ball = InitBall();

    game->bricks = malloc(brickRows * sizeof(Brick **));

    for (int i = 0; i < brickRows; i++) {
        game->bricks[i] = malloc(brickCols * sizeof(Brick *));

        for (int j = 0; j < brickCols; j++) {
            game->bricks[i][j] = InitBrick(i, j);
        }
    }

    return game;
}

void UpdateGame(Game *game) {
    UpdatePaddle(game->paddle);
    UpdateBall(game->ball);

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < brickCols; j++) {
            UpdateBrick(game->bricks[i][j]);
        }
    }
}

void DrawGame(Game *game) {
    DrawPaddle(game->paddle);
    DrawBall(game->ball);

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < brickCols; j++) {
            DrawBrick(game->bricks[i][j]);
        }
    }
}

void UnloadGame(Game *game) {
    UnloadPaddle(game->paddle);
    UnloadBall(game->ball);

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < brickCols; j++) {
            UnloadBrick(game->bricks[i][j]);
        }
    }

    free(game);
}
