CC=gcc
CFLAGS=-std=c11 -Wall -Wextra -O2
BIN=labyrinth

all: $(BIN)

$(BIN): main.c labyrinth.c labyrinth.h
	$(CC) $(CFLAGS) -o $@ main.c labyrinth.c

run: all
	./$(BIN)

clean:
	rm -f $(BIN)
.PHONY: test

test: $(BIN)
	mkdir -p tests
	$(CC) $(CFLAGS) -o tests/test_moves tests/test_moves.c labyrinth.c
	./tests/test_moves
