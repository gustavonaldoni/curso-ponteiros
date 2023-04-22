SOURCE_FILE = main.c
EXECUTABLE_NAME = main.out

CC = gcc
CFLAGS = -Wall -Werror

all:
	$(CC) $(SOURCE_FILE) -o $(EXECUTABLE_NAME) $(CFLAGS)

execute:
	./$(EXECUTABLE_NAME)

memcheck:
	valgrind --leak-check=full -s ./$(EXECUTABLE_NAME)