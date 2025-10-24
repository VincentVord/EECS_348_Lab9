# Makefile for Lab_9.cpp

# Compiler and flags
CC = g++
CFLAGS = -Wall -Wextra -std=c++11

# Targets (executables)
TARGETS = Lab_9

# Default target
all: $(TARGETS)

# Compile Lab_9
Lab_9: Lab_9.cpp
	$(CC) $(CFLAGS) -o Lab_9 Lab_9.cpp

# Clean up build files
clean:
	rm -f $(TARGETS)

# Run program
run: Lab_9
	./Lab_9
