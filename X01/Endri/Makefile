CC ?= gcc
CFLAGS ?= -std=c11 -Wall -Wextra -O2
INCLUDES = -Iinclude

SRC = src/main.c src/game.c src/maze.c src/input.c src/utils.c
OBJ = $(SRC:.c=.o)

TARGET = labyrinth

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: all
	./$(TARGET)