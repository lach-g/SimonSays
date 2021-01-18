#include "game.h"

int main(int argc, const char* argv[])
{
    list_t* commands;
    int continuing = 1;

    /* More than two arguments from command line
       quits program with runtime instructions displayed */
    if(argc > 2)
    {
        too_many_args();
        return -1;
    }

    /* Calloc the user linked list to take commands
    also containing a reference linked list of command descriptions */
    commands = create_user_list();

    /* Checking for arguments given and processes if so */
    if(argc > 1)
    {
        process_file_input(commands, argv);
    }

    /* set while condition to show the user menu at least once */
    do
    {
        menu(&continuing, commands);
    } while (continuing);
    
    free_list(commands);
    
    return 0;
}
