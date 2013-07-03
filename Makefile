all:
	gcc -std=c99 -pedantic -Wall -Wextra main.c -o ./iterations
clean:
	rm -f ./iterations