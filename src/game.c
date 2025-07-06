#include "game.h"

#include <stdio.h>
#include <stdlib.h>

#include "ball.h"
#include "brick.h"
#include "raymath.h"

Game *InitGame() {
    Game *game = malloc(sizeof(Game));

    game->paddle = InitPaddle();
    game->ball = InitBall();
    game->state = RUNNING;

    game->bricks = malloc(brickRows * sizeof(Brick **));

    for (int i = 0; i < brickRows; i++) {
        game->bricks[i] = malloc(brickCols * sizeof(Brick *));

        for (int j = 0; j < brickCols; j++) {
            game->bricks[i][j] = InitBrick(i, j);
        }
    }

    return game;
}

void UpdateGame(Game *game) {
    UpdatePaddle(game->paddle);
    UpdateBall(game->ball);

    /* Collision */
    if (CheckCollisionCircleRec(
            game->ball->position, game->ball->radius,
            (Rectangle){game->paddle->position.x, game->paddle->position.y,
                        game->paddle->size.x, game->paddle->size.y})) {
        /* Calculate new angle based on poi (distance from middle) */
        float distance = (game->ball->position.x - game->paddle->position.x) -
                         (game->paddle->size.x / 2);
        float angle = distance / (game->paddle->size.x / 2) * 45;

        game->ball->velocity = Vector2Scale(
            Vector2Rotate((Vector2){0, -1}, angle * DEG2RAD), ballSpeed);
    }

    bool collision = false;

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < brickCols; j++) {
            if (!game->bricks[i][j]) continue;

            if (CheckCollisionCircleRec(
                    game->ball->position, game->ball->radius,
                    (Rectangle){game->bricks[i][j]->position.x,
                                game->bricks[i][j]->position.y,
                                game->bricks[i][j]->size.x,
                                game->bricks[i][j]->size.y})) {
                game->ball->velocity.y *= -1;
                game->score++;

                Color c = game->bricks[i][j]->color;

                if (ColorIsEqual(c, RED))
                    game->ball->modifier = 1.75;
                else if (ColorIsEqual(c, ORANGE))
                    game->ball->modifier = 1.5;
                else if (ColorIsEqual(c, GREEN))
                    game->ball->modifier = 1.25;
                else
                    game->ball->modifier = 1.0;

                UnloadBrick(game->bricks[i][j]);
                game->bricks[i][j] = NULL;

                goto collision_handled;
            }
        }
    }

collision_handled:

    if (game->ball->position.y >= GetScreenHeight() - game->ball->radius) {
        FinishGame(game);
    }

    if (game->ball->position.y <= 0) {
        game->score += 50;

        FinishGame(game);
    }
}

void DrawGame(Game *game) {
    DrawPaddle(game->paddle);
    DrawBall(game->ball);

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < brickCols; j++) {
            if (!game->bricks[i][j]) {
                continue;
            }

            DrawBrick(game->bricks[i][j]);
        }
    }

    char score[20];
    sprintf(score, "%d", game->score);

    /* Text */
    DrawText(score, 16, 16, 48, WHITE);
}

GameState GetGameState(Game *game) { return game->state; }

Game *RestartGame(Game *game) {
    Game *newGame = InitGame();

    UnloadGame(game);

    return newGame;
}

void FinishGame(Game *game) { game->state = FINISHED; }

void UnloadGame(Game *game) {
    UnloadPaddle(game->paddle);
    UnloadBall(game->ball);

    for (int i = 0; i < brickRows; i++) {
        for (int j = 0; j < brickCols; j++) {
            if (!game->bricks[i][j]) {
                continue;
            }

            UnloadBrick(game->bricks[i][j]);
        }

        free(game->bricks[i]);
    }

    free(game->bricks);
    free(game);
}
