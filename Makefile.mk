# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
# The 'wildcard' function expands to all files in 
# the current directory that match the pattern *.c
SRCS = $(wildcard *.c)

# Executable files
# Replace the .c extension with nothing to get the executable names
EXES = $(SRCS:.c=)

# Default target
all: $(EXES)

# Compile each source file into its corresponding executable
%: %.c
    $(CC) $(CFLAGS) -o $@ $<

# Clean up build files
clean:
    rm -f $(EXES)