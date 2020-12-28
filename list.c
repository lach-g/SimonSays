#include <stdio.h>
#include <string.h>
#include "list.h"
#include "command.h"
#include "input_checking.h"
#include "queue.h"


list_t* create_user_list()
{
    list_t* user_list = create_a_list();
    user_list->reference_commands = create_command_reference_list();

    return user_list;
}

list_t* create_a_list()
{
    return calloc(1, sizeof(list_t));

}

void read_file_to_queue(char* filename, list_t* list)
{
    char string[COM_STRING_LEN];
    FILE* f = fopen(filename, "r");

    if(f == NULL)
    {
        perror("error opening the file: ");
    }
    else
    {
        while(fgets(string, COM_STRING_LEN, f))
        {
            int last_char = strlen(string) - 1;
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




void print_list(list_t* list)
{
    list_node_t* i;
    for(i = list->head; i != NULL; i = i->next)
    {
        print_command(i->data);
    }
}

void add_to_start_list(list_t* list, void* item_adding)
{    
    list_node_t* new_node = calloc(1, sizeof(list_node_t));
    new_node->data = item_adding;

    if(list->count == 0)
    {
        list->head = new_node;
        list->tail = new_node;
        list->count++; 
    }
    else
    {
        new_node->next = list->head;
        list->head = new_node;
        list->count++;
    }
}

void delete_items(list_t* list)
{
    int num_to_delete;
    printf("Enter number of commands to delete from start of queue:\n");
    int input_is_num = scan_for_int();
    if(input_is_num)
    {
        num_to_delete = input_is_num;

        while(num_to_delete > list->count)
        {
            printf("Choose number of commands to delete up to %d that are currently loaded:\n", list->count);
            //scanf("%d", &num_to_delete);
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
        if(num_to_delete == 1)
        {
            printf("\n\nSuccessfully deleted command.\n");
        }
        else
        {
            printf("\n\nSuccessfully deleted commands.\n");
            
        }
        
    }
    else
    {
        printf("\n\nOPTION QUIT: Must enter an integer\n");
    }
    
}

void free_list(list_t* list)
{
    list_t* references = list->reference_commands;
    free_a_list(references);
    free_a_list(list);
}

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
