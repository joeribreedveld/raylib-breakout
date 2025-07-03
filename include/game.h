#ifndef GAME_H
#define GAME_H

#include "paddle.h"

typedef struct Game {
    Paddle *paddle;
} Game;

Game *InitGame();

void UpdateGame(Game *game);

void DrawGame(Game *game);

void UnloadGame(Game *game);

#endif