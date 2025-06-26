# Name of the final executable
TARGET = game

# Source files
SRC = main.c

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Default rule: build the executable
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up build artifacts
clean:
	rm -f $(TARGET)

