#ifndef BRICK_H
#define BRICK_H

static const int brickHeight = 8;
static const int brickRows = 8;
static const int brickCols = 14;
static const int brickTopOffset = 78;
static const int brickGap = 4;

#include "raylib.h"

typedef struct Brick {
    Vector2 position;
    Vector2 size;
    Color color;
    bool isAlive;
} Brick;

Brick *InitBrick(int row, int col);

void UpdateBrick(Brick *brick);

void DrawBrick(Brick *brick);

Color GetBrickColor(int row);

void UnloadBrick(Brick *brick);

#endif