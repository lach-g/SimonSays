#include <stdio.h>
#include <unistd.h>
#include "asciiPrinting.h"

int main()
{
    /*
    void (*phase1)() = &print_dancing_stickman1;
    void (*phase2)() = &print_dancing_stickman2;
    void (*phase3)() = &print_dancing_stickman3;
    void (*phase4)() = &print_dancing_stickman4;
    */

    print_4_dance_phases(&print_dancing_stickman1, &print_dancing_stickman2, &print_dancing_stickman3, &print_dancing_stickman4);

    return 0;
}
