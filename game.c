#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "asciiPrinting.h"
#include "list.h"
#define COMMAND_LEN 1

int main()
{
    command_t* commands[COMMAND_LEN];

    int i;
    for(i = 0; i < COMMAND_LEN; i++)
    {
        commands[i] = createCommand();
    }

    for(i = 0; i < COMMAND_LEN; i++)
    {
        printCommand(commands[i]);
    }

    return 0;
}
