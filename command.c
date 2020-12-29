#include <stdio.h>
#include <string.h>
#include "command.h"
#include "asciiPrinting.h"
#include "list.h"
#include "queue.h"
#define NUM_MOVES 6
#define NUM_DESCRIPTIONS 5

/* Copies the second item in the input array into the filename variable created in main */
void scan_for_filename(char* argv[], char* filename)
{
    strcpy(filename, argv[1]);
}

/* Boolean that parses the end of a variable to check whether it has a txt file extension
   returning true if so */
int has_txt_extension(char* filename)
{
    
    char* extension = strrchr(filename, '.');
    if (!extension)
    {
        printf("File could not be read\n");
        return 0;
    }
    else
        if(strcmp(extension, ".txt") == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

/* Executes the function saved as a function pointer in the command struct */ 
void print_command(command_t* node)
{
    node->action();
}
