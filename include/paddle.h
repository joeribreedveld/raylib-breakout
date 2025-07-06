#ifndef PADDLE_H
#define PADDLE_H

static const int paddleWidth = 64;
static const int paddleHeight = 12;
static const int paddleDistanceFromBottom = 32;
static const float paddleSpeed = 300.0f;

#include "raylib.h"

typedef struct Paddle {
    Vector2 position;
    Vector2 size;
} Paddle;

Paddle *InitPaddle();

void UpdatePaddle(Paddle *paddle);

void DrawPaddle(Paddle *paddle);

int GetPaddleDirection();

void UnloadPaddle(Paddle *paddle);

#endif