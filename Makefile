CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Werror -pedantic

all: iterations


iterations: main.c
	$(CC) $(CFLAGS) main.c -o iterations

clean:
	rm -f *.o iterations