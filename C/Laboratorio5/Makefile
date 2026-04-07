# Makefile para compilar ejercicioplus.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
TARGET = ejercicioplus

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).o

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -c $(TARGET).c

clean:
	rm -f $(TARGET) $(TARGET).o

.PHONY: all clean
