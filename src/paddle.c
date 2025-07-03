#include "paddle.h"

#include <stdlib.h>

Paddle *InitPaddle() {
    Paddle *paddle = malloc(sizeof(Paddle));

    paddle->size = (Vector2){PADDLE_WIDTH, PADDLE_HEIGHT};
    paddle->position = (Vector2){
        (GetScreenWidth() - paddle->size.x) / 2,
        GetScreenHeight() - PADDLE_DISTANCE_FROM_BOTTOM - PADDLE_HEIGHT};

    return paddle;
}

void UpdatePaddle(Paddle *paddle) { return; }

void DrawPaddle(Paddle *paddle) {
    DrawRectangle(paddle->position.x, paddle->position.y, paddle->size.x,
                  paddle->size.y, WHITE);
}

void UnloadPaddle(Paddle *paddle) { free(paddle); }