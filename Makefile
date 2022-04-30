CC=gcc
CFLAGS=-Wall


all: main

clean:
	rm -f *.o main vgcore*


gameoflife.o: gameoflife.c
	$(CC) $(CFLAGS) -c $^

main: main.c gameoflife.o
	$(CC) $(CFLAGS) $^ -o $@
