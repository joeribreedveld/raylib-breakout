# Breakout

Breakout (1976) retro arcade game clone with raylib and C.

<img width="592" alt="Screenshot 2025-07-05 at 12 23 12" src="https://github.com/user-attachments/assets/198f1f90-64d3-4327-a115-1ab006405300" />

## Features

-   [x] Control paddle with keyboard arrows
-   [x] Ball bouncing on walls
-   [x] Multiple layers of profitable bricks
-   [x] Ball bouncing off entities
-   [x] Dynamic ball direction on paddle collision
-   [ ] Score and lives display

## Elements

### Paddle (player)

-   Variable (x-axis) position vector
-   Direction (on x-axis)
-   Constant speed
-   Dynamic bounce angle based on point of impact
-   Lose a life if ball is missed

### Brick

-   Constant position vector
-   Enum for level of brick
-   Break on impact and scale speed based on level
-   Increment game score on break

### Ball

-   Variable position vector
-   Calculate normalized direction on impact
-   Velocity only scaled by bricks

## Ideas for improvement

-   [ ] Multiplayer support
-   [ ] Highscore tracking
-   [ ] Power-up for paddle width and extra lives
-   [ ] Implement paddle velocity as vector for power-down
