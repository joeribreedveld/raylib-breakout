#include "ball.h"

#include <stdio.h>
#include <stdlib.h>

#include "raymath.h"

Ball *InitBall() {
    Ball *ball = malloc(sizeof(Ball));

    /* 90 degrees top or bottom */
    float angle;

    if (GetRandomValue(0, 1) == 0) {
        angle = (float)GetRandomValue(-45, 45);
    } else {
        angle = (float)GetRandomValue(135, 225);
    }

    ball->radius = ballRadius;
    ball->position =
        (Vector2){(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2};
    ball->velocity = Vector2Scale(
        Vector2Rotate((Vector2){0, 1}, angle * DEG2RAD), ballSpeed);

    return ball;
}

void UpdateBall(Ball *ball) {
    ball->position =
        Vector2Clamp(Vector2Add(ball->position,
                                Vector2Scale(ball->velocity, GetFrameTime())),
                     (Vector2){ball->radius, ball->radius},
                     (Vector2){GetScreenWidth() - ball->radius,
                               GetScreenHeight() - ball->radius});
}

void DrawBall(Ball *ball) {
    DrawCircle(ball->position.x, ball->position.y, ball->radius, WHITE);
}

void UnloadBall(Ball *ball) { free(ball); }
