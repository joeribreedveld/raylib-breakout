#ifndef BALL_H
#define BALL_H

#include "raylib.h"

static const int ballRadius = 8;
static const int ballSpeed = 400;
static const int angleMin1 = -45;
static const int angleMax1 = 45;
static const int angleMin2 = 135;
static const int angleMax2 = 225;

typedef struct Ball {
    Vector2 position;
    Vector2 velocity;
    int radius;
    float modifier;
} Ball;

Ball *InitBall();

void UpdateBall(Ball *ball);

void DrawBall(Ball *ball);

float GetInitialBallAngle();

void UnloadBall(Ball *ball);

#endif