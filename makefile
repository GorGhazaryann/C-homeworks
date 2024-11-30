# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
DEBUG_FLAGS = -g
OPTIM_FLAGS = -O2

# Target binary name
TARGET = sort_array

# Source files
SRC = sort_array.c

# Object files
OBJ = $(SRC:.c=.o)

# Default rule
all: debug

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Optimized build
optimized: CFLAGS += $(OPTIM_FLAGS)
optimized: $(TARGET)

# Compile and link
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Run Valgrind memory leak check
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# Generate documentation
docs:
	doxygen Doxyfile

.PHONY: all debug optimized clean valgrind docs
