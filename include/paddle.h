#ifndef PADDLE_H
#define PADDLE_H

#define PADDLE_WIDTH 48
#define PADDLE_HEIGHT 12
#define PADDLE_DISTANCE_FROM_BOTTOM 32

#include "raylib.h"

typedef struct Paddle {
    Vector2 position;
    Vector2 size;
} Paddle;

Paddle *InitPaddle();

void UpdatePaddle(Paddle *paddle);

void DrawPaddle(Paddle *paddle);

void UnloadPaddle(Paddle *paddle);

#endif