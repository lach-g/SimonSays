#include <stdio.h>
#include <string.h>
#include "command.h"
#include "asciiPrinting.h"
#include "list.h"
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
command_t* create_command_descript()
{

    command_t* command = malloc(1*sizeof(command_t));

    printf("Enter command:\n");
    scanf(" %[^\n]", command->description);
    //fgets(command->description, COM_STRING_LEN, stdin);
    //command->description[strlen(command->description) - 1] = '\0';
    create_command_action(command);
    return command;
    
}

command_t* create_file_command(char* line)
{
    command_t* command = malloc(1*sizeof(command_t));
    line[strlen(line) - 1] = '\0';
    strcpy(command->description, line);
    create_command_action(command);
    return command;
}


command_t* create_command_action(command_t* to_complete)
{
    char trick_command[COM_STRING_LEN];
    strcpy(trick_command, to_complete->description);
    trick_command[16] = '\0';

    if(strcmp(to_complete->description, "Simon says dance") == 0)
    {
        to_complete->action = &dance;
    }
    else if(strcmp(to_complete->description, "Simon says left wave") == 0)
    {
        to_complete->action = &left_wave;
    }
    else if(strcmp(to_complete->description, "Simon says right wave") == 0)
    {
        to_complete->action = &right_wave;
    }
    else if(strcmp(to_complete->description, "Simon says touch head") == 0)
    {
        to_complete->action = &touch_head;
    }
    else if(strcmp(trick_command, "Simon didn't say") == 0)
    {
        to_complete->action = &shake_head;
    }
    else
    {
        to_complete->action = &shrug;
    }

    return to_complete;
}


void printCommand(command_t* node)
{
    node->action();
    printf("Command is: %s\n", node->description);
}
