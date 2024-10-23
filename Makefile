CC=gcc
CFLAGS= -Wall -Werror -g

run: build
	./rps

build: main.c
	$(CC) $(CFLAGS) main.c -o rps


clean:
	rm -rf rps
