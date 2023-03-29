EXECUTABLE_NAME = main.out
SOURCE_FILE = src/main.c
LIB_FILES = $(wildcard lib/*.c)

CC = cc
CFLAGS = -Wall -Werror

ALL_FLAGS = $(CFLAGS)

all:
	$(CC) $(SOURCE_FILE) -o build/$(EXECUTABLE_NAME) $(LIB_FILES) $(ALL_FLAGS) -I./include

execute:
	build/$(EXECUTABLE_NAME)