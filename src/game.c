#include "game.h"

#include <stdlib.h>

#include "paddle.h"

Game *InitGame() {
    Game *game = malloc(sizeof(Game));

    game->paddle = InitPaddle();

    return game;
}

void UpdateGame(Game *game) { UpdatePaddle(game->paddle); }

void DrawGame(Game *game) { DrawPaddle(game->paddle); }

void UnloadGame(Game *game) {
    UnloadPaddle(game->paddle);

    free(game);
}
