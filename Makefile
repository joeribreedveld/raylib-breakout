CC=gcc
CFLAGS=-I/opt/homebrew/opt/raylib/include 
LDFLAGS=-L/opt/homebrew/opt/raylib/lib -lraylib
SRC=src/main.c
TARGET=breakout

default: ${TARGET}

${TARGET}:
	${CC} ${SRC} ${CFLAGS} ${LDFLAGS} -o ${TARGET} 

run: ${TARGET}
	./${TARGET}

clean:
	rm -f ${TARGET}