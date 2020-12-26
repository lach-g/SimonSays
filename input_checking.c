#include <stdlib.h>
#include <stdio.h>
#include "input_checking.h"
#include "command.h"

int is_integer(char* string)
{
    if(atoi(string) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int scan_if_int()
{
    char check_input[NUM_STRING_LEN];
    int converted_input;
    scanf("%8s",check_input);
    converted_input = atoi(check_input);
    if(converted_input)
    {
        return converted_input;
    }
    else
    {
        return 0;
    }
    

}

