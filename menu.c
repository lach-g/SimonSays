#include <stdio.h>
#include "menu.h"


void cancel_choice(int* choice)
{
    printf("(0) See Simon (1) Continue inputting\n");
    scanf("%d", choice);
    getchar();
}

void menu(int* cont)
{
    int choice;
    display_options();
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("1 selected\n");
            break;
        case 2:
            printf("2 selected\n");
            break;
    }



}

void display_options()
{
    printf("(1) Give Simon commands\n");
    printf("(2) Load commands from file\n");
    printf("(3) Delete commands\n");
    printf("(4) Play Simon Says\n");
    printf("(5) Play Simon Says\n"); 
}




