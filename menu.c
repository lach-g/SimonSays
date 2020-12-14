#include <stdio.h>
#include "menu.h"


void cancel_choice(int* choice)
{
    printf("(0) See Simon (1) Continue inputting\n");
    scanf("%d", choice);
    getchar();
}
