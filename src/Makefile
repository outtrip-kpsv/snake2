CC=gcc
CFLAG=-Wall -Wextra -Werror

all: game clean

game: main.c render.o game.o process.o
	$(CC) $(CFLAG) render.o main.c -o ../build/main -lncurses

render.o: render.c
	$(CC) $(CFLAG) -c render.c

game.o: game.c
	$(CC) $(CFLAG) -c game.c

process.o: process.c
	$(CC) $(CFLAG) -c process.c

clean:
	rm -rf *.o