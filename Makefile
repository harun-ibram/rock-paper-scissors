CC=gcc
CFLAGS= -Wall -Werror -g

build: main.o
	$(CC) $(CFLAGS) main.o -o rps

main.o: main.c

clean:
