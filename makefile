CFLAGS = -Wall -pedantic -ansi
OBJ = game.o asciiPrinting.o
EXEC = asciiArt
CC = gcc

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

game.o : game.c asciiPrinting.h
	$(CC) -c game.c $(CFLAGS)

asciiPrinting.o : asciiPrinting.c asciiPrinting.h
	$(CC) -c asciiPrinting.c $(CFLAGS)

# Cleaning directory
clean:
	rm -f $(EXEC) $(OBJ) 