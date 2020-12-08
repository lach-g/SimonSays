# Missing -ansi for compile time
CFLAGS = -Wall -pedantic
OBJ = game.o asciiPrinting.o command.o list.o
EXEC = asciiArt
CC = gcc

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

game.o : game.c asciiPrinting.h command.h list.h
	$(CC) -c game.c $(CFLAGS)

asciiPrinting.o : asciiPrinting.c asciiPrinting.h command.h
	$(CC) -c asciiPrinting.c $(CFLAGS)

command.o : command.c command.h asciiPrinting.h
	$(CC) -c command.c $(CFLAGS)

list.o : list.c list.h command.h
	$(CC) -c list.c $(CFLAGS)


# Cleaning directory
clean:
	rm -f $(EXEC) $(OBJ) 