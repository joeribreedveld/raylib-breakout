#include "game.h"

#include <stdlib.h>

#include "ball.h"
#include "paddle.h"

Game *InitGame() {
    Game *game = malloc(sizeof(Game));

    game->paddle = InitPaddle();
    game->ball = InitBall();

    return game;
}

void UpdateGame(Game *game) {
    UpdatePaddle(game->paddle);
    UpdateBall(game->ball);
}

void DrawGame(Game *game) {
    DrawPaddle(game->paddle);
    DrawBall(game->ball);
}

void UnloadGame(Game *game) {
    UnloadPaddle(game->paddle);
    UnloadBall(game->ball);

    free(game);
}
