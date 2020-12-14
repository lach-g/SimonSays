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
    list_t* commands = create_list();
    int choice = 1;
    int command_count = 0;

    while(choice)
    {
        
        // Adds a command from the terminal to the queue
        enqueue(commands, create_command());
        command_count++;
        
        cancel_choice(&choice);
    }

    for(int i = 0; i < command_count; i++)
    {
        command_t* command = dequeue(commands);
        command->action();
    }

    //free_list(commands);

    return 0;
}
