#include <stdio.h>
#include <string.h>
#include "list.h"
#include "command.h"
#include "input_checking.h"
#include "queue.h"


list_t* create_list()
{
    return calloc(1, sizeof(list_t));
}

void process_input(char* filename, list_t* list, int* input, int* track_commands)
{
    if(*input)
    { 
        read_file_to_queue(filename, list, track_commands);
    }

}

void read_file_to_queue(char* filename, list_t* list, int* track_commands)
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
            enqueue(list, create_file_command(string));
            (*track_commands)++;
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

void delete_items(list_t* list, int* command_count)
{
    int num_to_delete;
    printf("Enter number of commands to delete from start of queue:\n");
    int input_is_num = scan_for_int();
    if(input_is_num)
    {
        num_to_delete = input_is_num;

        while(num_to_delete > *command_count)
        {
            printf("Choose number of commands to delete up to %d that are currently loaded\n", *command_count);
            //scanf("%d", &num_to_delete);
            int input_is_num =  scan_for_int();
            if(input_is_num)
            {
                num_to_delete = input_is_num;
            }
        }


        for(int i = 0; i < num_to_delete; i++)
        {
            dequeue(list);
            (*command_count)--;
        }
        printf("\n\nSuccessfully deleted command(s).\n");
    }
    else
    {
        printf("\n\nOPTION QUIT: Must enter an integer\n");
    }
    
}
    
