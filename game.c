#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "asciiPrinting.h"
#include "command.h"
#include "list.h"
#include "menu.h"
#define COMMAND_LEN 2

int main(int argc, char* argv[])
{
    if(argc > 2)
    {
        printf("Too many command line arguments provided\n");
        printf("Run either with zero or one filename to read in.\n");
        return -1;
    }


    /* Calloc linked list */
    list_t* commands = create_list();
    
    /* set while condition to begin at least once */
    int continuing = 1;

    /* Number of commands input */
    int command_count = 0;

    /* Filename and bool for command line input */
    char filename[FILE_STRING_LEN];
    int input = 0;

    /* Checking for arguments given and processing if so */
    scan_input(&argc, argv, filename, &input);
    process_input(filename, commands, &input, &command_count);

    do
    {
        menu(&continuing, &command_count, commands);
    } while (continuing);


    //free_list(commands);
    
    return 0;
}
