#include <stdio.h>
#include <string.h>
#include "command.h"
#include "asciiPrinting.h"
#include "list.h"
#include "queue.h"

/* Boolean that parses the end of a variable to check whether it has a txt file extension
   returning true if so */
int has_txt_extension(const char* filename)
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
void print_command(const command_t* node)
{
    node->action();
}
