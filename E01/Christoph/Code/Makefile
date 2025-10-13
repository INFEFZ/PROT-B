# Compiler
CC = gcc
CFLAGS = -Wall -g

# Zielname
TARGET = spiel

# Quellcode-Dateien
SRCS = main.c Labyrinth.c Spieler.c
OBJS = $(SRCS:.c=.o)

# Standardziel: baue und führe aus
game: $(TARGET)
	./$(TARGET)

# Wie das Ziel gebaut wird
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Objektdateien erzeugen
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Aufräumen
clean:
	rm -f $(TARGET) $(OBJS)
