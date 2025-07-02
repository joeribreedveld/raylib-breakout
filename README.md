# Breakout

Breakout (1976) retro arcade game clone with raylib and C.

## Features

-   [ ] Control paddle with keyboard arrows
-   [ ] Ball bouncing on walls and entities
-   [ ] Dynamic ball direction on paddle collision
-   [ ] Score and lives display
-   [ ] Multiple layers of profitable bricks

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
-   [ ] Powerup for paddle width and extra lives
