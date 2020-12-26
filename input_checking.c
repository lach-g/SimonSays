#include <stdlib.h>

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
