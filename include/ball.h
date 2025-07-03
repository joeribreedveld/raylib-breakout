#ifndef BALL_H
#define BALL_H

#include "raylib.h"

static const int ballRadius = 8;
static const int ballSpeed = 200;

typedef struct Ball {
    Vector2 position;
    Vector2 velocity;
    int radius;
} Ball;

Ball *InitBall();

void UpdateBall(Ball *ball);

void DrawBall(Ball *ball);

void UnloadBall(Ball *ball);

#endif