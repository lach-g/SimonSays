#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

/* Reassigns a pointer variable to a user input integer */
void cancel_choice(int* choice)
{
    printf("(1) Finish (2) Continue inputting\n");
    int input_is_num = scan_for_int();
    if(input_is_num && input_is_num < 3)
    {
        *choice = input_is_num - 1;
    }
    else
    {
        *choice = 0;
    }
    
}

/* Displays the user options and takes user input as integer
   for choosing an option */
void menu(int* cont, list_t* list)
{
    int choice;
    display_options();
    int input_is_num = scan_for_int();

    if(input_is_num)
    {
        choice = input_is_num;
        switch(choice)
        {
            case ENTER_COMMANDS:
                enter_commands(list);
                break;
            case LOAD_FILE_COMMANDS:
                load_file_commands(list);
                break;
            case DELETE_COMMANDS:
                delete_items(list);
                break;
            case PLAY:
                play_actions(list);
                break; 
            case EXIT:
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

/* Prints to terminal either Normal Mode Menu Options or Everything
   Mode Menu Options based on conditional compilation */
void display_options()
{
    #ifdef EVERYTHING
    printf("--------------------------------------\n");
    printf("         TO PLAY SIMON SAYS\n");
    printf("          EVERYTHING MODE\n");
    printf("    SELECT FROM THE OPTIONS BELOW:\n");
    printf("--------------------------------------\n");
    printf("(1) Give Simon commands\n");
    printf("(2) Load commands from file\n");
    printf("(3) Delete commands\n");
    printf("(4) Play Simon Says\n");
    printf("(5) Exit application\n");
    #endif
    #ifndef EVERYTHING
    printf("--------------------------------------\n");
    printf("         TO PLAY SIMON SAYS\n");
    printf("    SELECT FROM THE OPTIONS BELOW:\n");
    printf("--------------------------------------\n");
    printf("(1) Give Simon commands\n");
    printf("(2) Load commands from file\n");
    printf("(3) Delete commands\n");
    printf("(4) Play Simon Says\n");
    printf("(5) Exit application\n");
    #endif
}

   /* Taking Simon says commands into Linked List */
void enter_commands(list_t* list)
{
    int entering_comm = 1;
    do
    {
        // Adds a command from the terminal to the queue
        command_t* new_command = initiate_input_to_command(list->reference_commands); 
        enqueue(list, new_command);
        cancel_choice(&entering_comm);

    }while(entering_comm);
 }

/* Using queue to pop each Simon Says command off in order of input */
void play_actions(list_t* list)
{
    if(list->count > 0)
    {
        int command_count = list->count;
        for(int i = 0; i < command_count; i++)
        {
            command_t* command = dequeue(list);
            command->action();
            free(command);
        }
    }
    else
    {
        printf("\n\nNO COMMANDS QUEUED\n");
    }
    

}

/* Takes in string and prcocesses to read as a file */
void load_file_commands(list_t* list)
{
    char file_name_to_read[FILE_STRING_LEN];
    
    printf("Enter filename:\n");
    // scanf(" %[^\n]", file_name_to_read);
    int flush;
    while((flush = getchar()) != '\n' && flush != EOF);

    fgets(file_name_to_read, FILE_STRING_LEN, stdin);
    int len = strlen(file_name_to_read);
    if(len > 0 && file_name_to_read[len - 1] == '\n')
    {
        file_name_to_read[--len] = '\0';
    }
    read_file_to_queue(file_name_to_read, list);
}
