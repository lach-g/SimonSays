#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "asciiPrinting.h"
#include "command.h"
#include "list.h"
#include "input_checking.h"
#include "menu.h"

int main(int argc, char* argv[])
{
    /* More than two arguments from command line
       quits program with runtime instructions displayed */
    if(argc > 2)
    {
        too_many_args();
        return -1;
    }

    /* Calloc the user linked list containing a reference list of
       command descriptions */
    list_t* commands = create_user_list();

    /* Checking for arguments given and processes if so */
    if(argc > 1)
    {
        process_file_input(commands, argv);
    }

    /* set while condition to show the user menu at least once */
    int continuing = 1;
    do
    {
        menu(&continuing, commands);
    } while (continuing);
    
    free_list(commands);
    
    return 0;
}
