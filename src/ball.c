
#include "ball.h"

#include <stdio.h>
#include <stdlib.h>

#include "raymath.h"
#include "utils.h"

Ball *InitBall() {
    Ball *ball = malloc(sizeof(Ball));

    ball->radius = ballRadius;
    ball->position =
        (Vector2){(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};

    /* Calculate initial direction and apply speed */
    ball->velocity = Vector2Scale(
        Vector2Rotate((Vector2){0, 1}, GetInitialBallAngle()), ballSpeed);

    return ball;
}

void UpdateBall(Ball *ball) {
    ball->position = Vector2Add(ball->position,
                                Vector2Scale(ball->velocity, GetFrameTime()));

    /* Bounce off side walls */
    ReflectClamp(&ball->position.x, &ball->velocity.x, ball->radius,
                 GetScreenWidth() - ball->radius);

    /* Ceiling is finish */

    /* Floor is death */
}

void DrawBall(Ball *ball) {
    DrawCircle(ball->position.x, ball->position.y, ball->radius, WHITE);
}

float GetInitialBallAngle() {
    if (GetRandomValue(0, 1) == 0) {
        return (float)GetRandomValue(-45, 45) * DEG2RAD;
    } else {
        return (float)GetRandomValue(135, 225) * DEG2RAD;
    }
}

void UnloadBall(Ball *ball) { free(ball); }
