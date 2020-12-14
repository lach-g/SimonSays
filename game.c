#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "asciiPrinting.h"
#include "command.h"
#include "list.h"
#include "menu.h"
#define COMMAND_LEN 2

int main()
{
    int choice = 1;

    while(choice)
    {
        cancel_choice(&choice);
        
        // Create the list
        list_t* commands = create_list();

        enqueue(commands, create_command());

        for(int i = 0; i < COMMAND_LEN; i++)
        {
            command_t* command = dequeue(commands);
            command->action();
        }
    }

    //free_list(commands);

    return 0;
}
