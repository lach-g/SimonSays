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
    process_input(filename, commands, &input);



    /* Taking Simon says commands into Linked List */
    while(continuing)
    {

        
        // Adds a command from the terminal to the queue
        enqueue(commands, create_command_descript());
        command_count++;

        cancel_choice(&continuing);
    }




    /* Using queue to pop each Simon Says command in order of input */
    for(int i = 0; i < command_count; i++)
    {
        command_t* command = dequeue(commands);
        command->action();
    }

    //free_list(commands);

    return 0;
}
