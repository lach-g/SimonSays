#include <stdio.h>
#include <string.h>
#include "command.h"
#include "asciiPrinting.h"
#include "list.h"
#include "queue.h"
#define NUM_MOVES 6
#define NUM_DESCRIPTIONS 5

void scan_for_filename(char* argv[], char* filename)
{
    strcpy(filename, argv[1]);
}

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

void print_command(command_t* node)
{
    node->action();
}
