# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -O2

# Name of the final executable
TARGET = generatePrime

# Source files (main.c is in the current folder; cryptoLib.c is in the parent folder)
SOURCES = main.c ../cryptoLib.c

# Object files (keep in mind the relative paths)
OBJECTS = main.o ../cryptoLib.o

# Default target: build the executable
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile main.c (depends on cryptoLib.h in the parent directory)
main.o: main.c ../cryptoLib.h
	$(CC) $(CFLAGS) -c main.c -o main.o

# Compile cryptoLib.c from the parent directory
../cryptoLib.o: ../cryptoLib.c ../cryptoLib.h
	$(CC) $(CFLAGS) -c ../cryptoLib.c -o ../cryptoLib.o

# Clean up generated files
clean:
	rm -f $(TARGET) main.o ../cryptoLib.o