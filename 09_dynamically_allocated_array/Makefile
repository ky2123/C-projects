# TODO write the Makefile
all: main

main: main.c intarray.o
	gcc -Wall -Wextra -pedantic -std=c17 -g -fsanitize=address main.c intarray.o -o run
intarray.o: intarray.c
	gcc -Wall -Wextra -pedantic -std=c17 -g -fsanitize=address -c intarray.c -o intarray.o
main.o: main.c 
	gcc -Wall -Wextra -pedantic -std=c17 -g -fsanitize=address -c main.c -o main.o	
