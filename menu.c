#include <stdio.h>
#include "list.h"
#include "menu.h"


void cancel_choice(int* choice)
{
    printf("(0) Finish (1) Continue inputting\n");
    scanf("%d", choice);
    getchar();
}

void menu(int* cont, int* command_count, list_t* list)
{
    int choice;
    display_options();
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            enter_commands(command_count, list);
            break;
        case 2:
            printf("2 selected\n");
            break;
        case 3:
            printf("3 selected\n");
            break;
        case 4:
            play_actions(list, command_count);
            break;
        case 5:
            printf("5 selected\n");
            break;
        case 6:
            *cont = 0;
            break;
    }



}

void display_options()
{
    printf("(1) Give Simon commands\n");
    printf("(2) Load commands from file\n");
    printf("(3) Delete commands\n");
    printf("(4) Play Simon Says\n");
    printf("(6) Exit application\n"); 
}

   /* Taking Simon says commands into Linked List */
void enter_commands(int* command_count, list_t* list)
{
    int entering_comm = 1;
    do
    {
        // Adds a command from the terminal to the queue
        enqueue(list, create_command_descript());
        command_count++;

        cancel_choice(&entering_comm);
    }while(entering_comm);
    }

/* Using queue to pop each Simon Says command in order of input */
void play_actions(list_t* list, int* command_count)
{
    for(int i = 0; i < *command_count; i++)
    {
        command_t* command = dequeue(list);
        command->action();
    }
}

