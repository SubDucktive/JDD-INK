CC = clang
TARGET = bin/jdd-ink
SRC = src/main.c
INCLUDES = $(shell sdl2-config --cflags)
LIBS = $(shell sdl2-config --libs)

all:
	$(CC) $(SRC) $(INCLUDES) $(LIBS) -o $(TARGET)