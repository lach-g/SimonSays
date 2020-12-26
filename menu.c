#include <stdio.h>
#include "list.h"
#include "menu.h"
#include "input_checking.h"


void cancel_choice(int* choice)
{
    char check_choice[NUM_STRING_LEN];
    printf("(1) Finish (2) Continue inputting\n");
    scanf("%8s", check_choice);
    if(is_integer(check_choice))
    {
        *choice = atoi(check_choice);
        *choice = *choice - 1;
    }
}

void menu(int* cont, int* command_count, list_t* list)
{
    int choice;
    char check_choice[NUM_STRING_LEN];
    display_options();
    scanf("%8s", check_choice);
    if(is_integer(check_choice))
    {
        choice = atoi(check_choice);
        switch(choice)
        {
            case 1:
                enter_commands(command_count, list);
                break;
            case 2:
                load_file_commands(list, command_count);
                break;
            case 3:
                delete_items(list, command_count);
                break;
            case 4:
                play_actions(list, command_count);
                break;
            case 5:
                *cont = 0;
                break;
            default:
                printf("\n\nENTER 1-5 INCLUSIVE FROM DISPLAYED OPTIONS\n");
                break;
                
        }
    }
    else
    {
        printf("\n\nENTER 1-5 INCLUSIVE FROM DISPLAYED OPTIONS\n");
    }
    


}

void display_options()
{
    printf("--------------------------------------\n");
    printf("         TO PLAY SIMON SAYS\n");
    printf("    SELECT FROM THE OPTIONS BELOW:\n");
    printf("--------------------------------------\n");
    printf("(1) Give Simon commands\n");
    printf("(2) Load commands from file\n");
    printf("(3) Delete commands\n");
    printf("(4) Play Simon Says\n");
    printf("(5) Exit application\n"); 
}

   /* Taking Simon says commands into Linked List */
void enter_commands(int* command_count, list_t* list)
{
    int entering_comm = 1;
    do
    {
        // Adds a command from the terminal to the queue
        command_t* new_command = create_command_descript(); 
        enqueue(list, new_command);
        (*command_count)++;
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
    *command_count = 0;
}

/* Takes in string and prcocesses to read as a file */
void load_file_commands(list_t* list, int* command_count)
{
    char file_name_to_read[FILE_STRING_LEN];
    
    printf("Enter filename:\n");
    scanf(" %[^\n]", file_name_to_read);
    read_file_to_queue(file_name_to_read, list, command_count);
}

