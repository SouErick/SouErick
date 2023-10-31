# Makefile
CC = gcc
CFLAGS = -Wall

SRC = main.c aritmetico.c controle.c leitura.c logica.c memoria.c saida.c

OBJ = $(SRC:.c=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)