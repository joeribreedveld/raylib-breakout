CC=gcc
CFLAGS=-Iinclude -I/opt/homebrew/opt/raylib/include
LDFLAGS=-L/opt/homebrew/opt/raylib/lib -lraylib
SRC=src/main.c src/ball.c src/brick.c src/game.c src/paddle.c src/utils.c
TARGET=breakout

default: all

all:
	${CC} ${SRC} ${CFLAGS} ${LDFLAGS} -o ${TARGET} 

run: all
	./${TARGET}

clean:
	rm -f ${TARGET}