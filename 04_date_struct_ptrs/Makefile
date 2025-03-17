all: main

main: main.o date.o
	gcc -Wall -Wextra -pedantic -std=c17 -g -fsanitize=address main.o date.o -o main

date.o: date.c
	gcc -Wall -Wextra -pedantic -std=c17 -g -fsanitize=address -c date.c -o date.o
main.o: main.c
	gcc -Wall -Wextra -pedantic -std=c17 -g -fsanitize=address -c main.c -o main.o

clean:
	rm -f *.o
