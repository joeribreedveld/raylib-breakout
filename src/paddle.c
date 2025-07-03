#include "paddle.h"

#include <stdlib.h>

#include "raymath.h"

Paddle *InitPaddle() {
    Paddle *paddle = malloc(sizeof(Paddle));

    paddle->size = (Vector2){paddleWidth, paddleHeight};
    paddle->position = (Vector2){
        (GetScreenWidth() - paddle->size.x) / 2,
        GetScreenHeight() - paddleDistanceFromBottom - paddle->size.y};

    return paddle;
}

void UpdatePaddle(Paddle *paddle) {
    int direction = GetPaddleDirection();

    if (direction == 0) {
        return;
    }

    paddle->position.x =
        Clamp(paddle->position.x + direction * paddleSpeed * GetFrameTime(), 0,
              GetScreenWidth() - paddle->size.x);
}

void DrawPaddle(Paddle *paddle) {
    DrawRectangle(paddle->position.x, paddle->position.y, paddle->size.x,
                  paddle->size.y, BLUE);
}

int GetPaddleDirection() {
    if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT)) {
        return 0;
    }

    if (IsKeyDown(KEY_LEFT)) {
        return -1;
    }

    if (IsKeyDown(KEY_RIGHT)) {
        return 1;
    }

    return 0;
}

void UnloadPaddle(Paddle *paddle) { free(paddle); }