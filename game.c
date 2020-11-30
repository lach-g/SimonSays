#include <stdio.h>
#include <unistd.h>
#include "asciiPrinting.h"
#define STICK_REPEAT 5

int main()
{
    int i;
    for(i = 0; i < STICK_REPEAT; i++)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_stick_man();
        sleep(1);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_stick_man_wave();
        sleep(1);
    }
    return 0;
}
