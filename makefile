# Missing -ansi for compile time
# Usage for EVERYTHING MODE: 'make CFLAGS="-D EVERYTHING'
CFLAGS = -Wall -pedantic
OBJ = game.o asciiPrinting.o command.o list.o menu.o input_checking.o queue.o
EXEC = asciiArt
CC = gcc

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

game.o : game.c asciiPrinting.h command.h list.h menu.h input_checking.o
	$(CC) -c game.c $(CFLAGS)

asciiPrinting.o : asciiPrinting.c asciiPrinting.h command.h
	$(CC) -c asciiPrinting.c $(CFLAGS)

command.o : command.c command.h asciiPrinting.h list.h queue.h
	$(CC) -c command.c $(CFLAGS)

list.o : list.c list.h command.h
	$(CC) -c list.c $(CFLAGS)

menu.o : menu.c menu.h input_checking.h queue.h
	$(CC) -c menu.c $(CFLAGS)

input_checking.o : input_checking.c input_checking.h list.h command.h
	$(CC) -c input_checking.c $(CFLAGS)

queue.o : queue.c list.h
	$(CC) -c queue.c $(CFLAGS)


# Cleaning directory
clean:
	rm -f $(EXEC) $(OBJ) 