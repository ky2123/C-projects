# TODO write makefile with rules for main, main.o, growable_array.o
CC=gcc
CFLAGS=-Wall -Wextra -std=c17 -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

PROG=main
OBJS=$(PROG).o growable_array.o 

all: main

$(PROG): $(OBJS)

clean:
	rm -f *.o main	
