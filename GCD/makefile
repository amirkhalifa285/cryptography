# Compiler
CC = gcc

# Compiler flags: 
# -Wall and -Wextra turn on most warnings
# -O2 enables optimizations
CFLAGS = -Wall -Wextra -O2

# Target executable name
TARGET = testGCD

# Source files and their corresponding object files
SOURCES = main.c ../cryptoLib.c
OBJECTS = main.o ../cryptoLib.o

# Default rule
all: $(TARGET)

# Link object files into the final executable
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# Compile main.c to main.o
main.o: main.c ../cryptoLib.h
	$(CC) $(CFLAGS) -c main.c -o main.o 

../cryptoLib.o: ../cryptoLib.c ../cryptoLib.h
	$(CC) $(CFLAGS) -c ../cryptoLib.c -o ../cryptoLib.o

# Clean rule to remove compiled files
clean:
	rm -f $(TARGET) main.o ../cryptoLib.o