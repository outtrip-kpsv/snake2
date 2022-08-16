CC=gcc
CFLAG=-Wall -Wextra -Werror

all: game snaketest clean

game: main.c structures.o render.o game.o process.o  properties.o snake.o key_handler.o
	$(CC) $(CFLAG) main.c render.o game.o process.o snake.o structures.o properties.o key_handler.c -o ../build/main -lncurses

snaketest: snake_test.c snake.o structures.o
	$(CC) $(CFLAG) snake_test.c snake.o structures.o -o ../build/testsnake

render.o: render.c
	$(CC) $(CFLAG) -c render.c

game.o: game.c
	$(CC) $(CFLAG) -c game.c

process.o: process.c
	$(CC) $(CFLAG) -c process.c

structures.o: structures.c
	$(CC) $(CFLAG) -c structures.c

snake.o: snake.c
	$(CC) $(CFLAG) -c snake.c

properties.o: properties.c
	$(CC) $(CFLAG) -c properties.c

key_handler.o: key_handler.c
	$(CC) $(CFLAG) -c key_handler.c

clean:
	rm -rf *.o