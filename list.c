#include <stdio.h>
#include <string.h>
#include "list.h"
#include "input_checking.h"
#include "queue.h"

/* Returns 1 linked list with a sub linked list prefilled
   with command descriptions for reference against input */ 
list_t* create_user_list()
{
    list_t* user_list = create_a_list();
    user_list->reference_commands = create_command_reference_list();

    return user_list;
}

/* Returns a heap memory allocated linked list */
list_t* create_a_list()
{
    return calloc(1, sizeof(list_t));

}

/* Opens a file stream and adds each line as a command to the user list */
void read_file_to_queue(const char* filename, list_t* list)
{
    char string[COMMAND_STRING_LEN];
    FILE* f = fopen(filename, "r");

    if(f == NULL)
    {
        perror("error opening the file: ");
    }
    else
    {
        while(fgets(string, COMMAND_STRING_LEN, f))
        {
            const int last_char = strlen(string) - 1;
            if(string[last_char] == '\n')
            {
                string[last_char] = '\0';
            }
            enqueue(list, process_file_line_to_command(string, list->reference_commands));
        }
        printf("\n\nFILE SUCCESSFULLY READ\n");
    }
    fclose(f); 
}

/* CLEAN THIS */
void delete_items(list_t* list)
{
    if(list->count > 0)
    {
        printf("Enter number of commands to delete from start of queue:\n");
        int num_to_delete = scan_for_int();
        if(num_to_delete)
        {
            while(num_to_delete > list->count)
            {
                printf("Choose number of commands to delete up to %d that are currently loaded:\n", list->count);
                int input_is_num =  scan_for_int();
                if(input_is_num)
                {
                    num_to_delete = input_is_num;
                }
            }

            for(int i = 0; i < num_to_delete; i++)
            {
                command_t* command = dequeue(list);
                free(command);
            }
            delete_message(&num_to_delete);  
        }
        else
        {
            printf("\n\nOPTION QUIT: Must enter an integer\n");
        }
    }
    else
    {
        printf("\n\nNO COMMANDS QUEUED\n");
    }
}

/* Ensures the confirmation of success in deleting has the correct conjugation */
void delete_message(const int* total_deleted)
{
    if(*total_deleted == 1)
        {
            printf("\n\nSuccessfully deleted command.\n");
        }
        else
        {
            printf("\n\nSuccessfully deleted commands.\n");
            
        }
}

/* Takes the user input list and frees it and the reference list inside it */
void free_list(list_t* list)
{
    list_t* references = list->reference_commands;
    free_a_list(references);
    free_a_list(list);
}

/* Frees a linked list node by node */
void free_a_list(list_t* list)
{
    list_node_t* current = list->head;
    while(current != NULL)
    {
        list_node_t* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(list);
}
