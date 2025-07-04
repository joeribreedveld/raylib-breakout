#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "brick.h"
#include "paddle.h"

typedef struct Game {
    Paddle *paddle;
    Ball *ball;
    Brick ***bricks;
} Game;

Game *InitGame();

void UpdateGame(Game *game);

void DrawGame(Game *game);

void UnloadGame(Game *game);

#endif