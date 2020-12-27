#include <stdio.h>
#include <string.h>
#include "command.h"
#include "asciiPrinting.h"
#include "list.h"
#include "queue.h"
#define NUM_MOVES 6
#define NUM_DESCRIPTIONS 5

void scan_input(char* argv[], char* filename)
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


command_t* create_file_command(char* line)
{
    command_t* command = malloc(1*sizeof(command_t));
    line[strlen(line)] = '\0';
    printf("%s", line);
    strcpy(command->description, line);
    create_command_action(command);
    return command;
}

/* for the struct functions */
command_t* create_command_descript()
{

    command_t* command = malloc(1*sizeof(command_t));

    printf("Enter command:\n");
    scanf(" %128[^\n]", command->description);
    //fgets(command->description, COM_STRING_LEN, stdin);
    //command->description[strlen(command->description) - 1] = '\0';
    create_command_action(command);
    return command;
    
}

void print_command(command_t* node)
{
    node->action();
}
