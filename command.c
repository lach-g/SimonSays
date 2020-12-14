#include <stdio.h>
#include <string.h>
#include "command.h"
#include "asciiPrinting.h"
#define NUM_MOVES 6

void scan_input(int* arg_count, char* argv[], char* filename, int* input)
{
    if(*arg_count > 1)
    {
        *input = 1;
        strcpy(filename, argv[1]);
    }
}

/* for the struct functions */
command_t* create_command()
{

    command_t* command = malloc(1*sizeof(command_t));
    char trick_command[COM_STRING_LEN];

    printf("Enter command:\n");
    //scanf(" %[^\n]", command.description);
    fgets(command->description, COM_STRING_LEN, stdin);
    command->description[strlen(command->description) - 1] = '\0';

    strcpy(trick_command, command->description);
    trick_command[16] = '\0';

    if(strcmp(command->description, "Simon says dance") == 0)
    {
        command->action = &dance;
    }
    else if(strcmp(command->description, "Simon says left wave") == 0)
    {
        command->action = &left_wave;
    }
    else if(strcmp(command->description, "Simon says right wave") == 0)
    {
        command->action = &right_wave;
    }
    else if(strcmp(command->description, "Simon says touch head") == 0)
    {
        command->action = &touch_head;
    }
    else if(strcmp(trick_command, "Simon didn't say") == 0)
    {
        command->action = &shake_head;
    }
    else
    {
        command->action = &shrug;
    }

    return command;
}


void printCommand(command_t* node)
{
    node->action();
    printf("Command is: %s\n", node->description);
}
