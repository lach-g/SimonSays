#include <stdio.h>
#include <unistd.h>
#include "asciiPrinting.h"
#define STICK_REPEAT 5

int main()
{
    int i;
    for(i = 0; i < STICK_REPEAT; i++)
    {
        print_stick_man();
        printf("\n\n\n\n\n\n\n\n\n");
        sleep(1);
        print_stick_man_wave();
    }
    return 0;
}
