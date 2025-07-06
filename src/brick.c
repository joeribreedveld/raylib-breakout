#include "brick.h"

#include <stdlib.h>

Brick *InitBrick(int row, int col) {
    Brick *brick = malloc(sizeof(Brick));

    /* Calculate positions based with gap offsets */
    float brickWidth =
        ((float)GetScreenWidth() - ((brickCols + 1) * brickGap)) / brickCols;

    brick->position =
        (Vector2){(col + 1) * brickGap + col * brickWidth,
                  ((row + 1) * brickGap) + row * brickHeight + brickTopOffset};

    brick->size = (Vector2){brickWidth, brickHeight};
    brick->color = GetBrickColor(row);
    brick->isAlive = true;

    return brick;
}

void UpdateBrick(Brick *brick) { return; }

void DrawBrick(Brick *brick) {
    if (!brick) {
        return;
    }

    DrawRectangle(brick->position.x, brick->position.y, brick->size.x,
                  brick->size.y, brick->color);
}

Color GetBrickColor(int row) {
    if (row / 2 == 0) {
        return RED;
    }

    if (row / 2 == 1) {
        return ORANGE;
    }

    if (row / 2 == 2) {
        return GREEN;
    }

    return YELLOW;
}

void UnloadBrick(Brick *brick) { free(brick); }