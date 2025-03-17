CC=gcc
CFLAGS=-Wall -Wextra -std=c17 -pedantic -g -fsanitize=address
LDFLAGS=-fsanitize=address

PROG=main
OBJS=$(PROG).o bst.o

all: $(PROG)

$(PROG): $(OBJS)

clean:
	rm -f *.o $(PROG)
