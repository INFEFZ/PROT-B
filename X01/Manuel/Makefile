# --- Praxisarbeit Maze: Build & Run ---
TARGET := labyrinth
CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -O2 -Isrc

# automatically collect all .c files in src/
SRCS := $(wildcard src/*.c)
BIN  := bin
BUILD:= build
OBJS := $(patsubst src/%.c,$(BUILD)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all run clean rebuild

# Default target: build the executable
all: $(BIN)/$(TARGET).exe

# Link step: combine all object files into the final binary
$(BIN)/$(TARGET).exe: $(OBJS) | $(BIN)
	$(CC) $(CFLAGS) $^ -o $@

# Compile step with header dependency generation (-MMD -MP)
$(BUILD)/%.o: src/%.c | $(BUILD)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# Ensure output directories exist
$(BIN) $(BUILD):
	mkdir -p $@

# Build and immediately run the game
run: $(BIN)/$(TARGET).exe
	./$(BIN)/$(TARGET).exe

# Remove build artifacts and the binary
clean:
	rm -rf $(BUILD) $(BIN)/$(TARGET).exe

# Include generated dependency files (if present)
-include $(DEPS)
