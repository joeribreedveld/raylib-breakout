#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "brick.h"
#include "paddle.h"

typedef enum {
    DEFAULT,
    RUNNING,
    FINISHED,
} GameState;

typedef struct Game {
    Paddle *paddle;
    Ball *ball;
    Brick ***bricks;
    int score;
    GameState state;
} Game;

Game *InitGame();

void UpdateGame(Game *game);

void DrawGame(Game *game);

GameState GetGameState(Game *game);

void FinishGame(Game *game);

Game *RestartGame(Game *game);

void UnloadGame(Game *game);

#endif