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
        print_dancing_stickman1();
        usleep(250000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_dancing_stickman2();
        usleep(250000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_dancing_stickman3();
        usleep(250000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_dancing_stickman4();
        usleep(250000);
    }
    return 0;
}
