#include <stdio.h>
#include "list.h"
#include "menu.h"
#include "input_checking.h"
#include "queue.h"


void cancel_choice(int* choice)
{
    printf("(1) Finish (2) Continue inputting\n");
    int input_is_num = scan_for_int();
    if(input_is_num && input_is_num < 2)
    {
        *choice = input_is_num - 1;
    }
    else
    {
        printf("\n\nOPTION QUIT: Input must be either 1 or 2\n");
        *choice = 0;
    }
    
}

void menu(int* cont, int* command_count, list_t* list)
{
    int choice;
    display_options();
    int input_is_num = scan_for_int();

    if(input_is_num)
    {
        choice = input_is_num;
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
    if(*command_count > 0)
    {
        for(int i = 0; i < *command_count; i++)
        {
            command_t* command = dequeue(list);
            command->action();
        }
        *command_count = 0;
    }
    else
    {
        printf("\n\nNO COMMANDS QUEUED\n");
    }
    

}

/* Takes in string and prcocesses to read as a file */
void load_file_commands(list_t* list, int* command_count)
{
    char file_name_to_read[FILE_STRING_LEN];
    
    printf("Enter filename:\n");
    scanf(" %[^\n]", file_name_to_read);
    read_file_to_queue(file_name_to_read, list, command_count);
}

