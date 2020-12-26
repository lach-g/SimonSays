#include <stdio.h>
#include "list.h"
#include "command.h"


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
        printCommand(i->data);
    }
}

void free_list(list_t* list)
{
    list_node_t* current;
    current = list->head;
    while(current != NULL)
    {
        list_node_t* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    free(list);
}

command_t* dequeue(list_t* list)
{
    list_node_t* temp = list->head;
    list->head = list->head->next;

    if(list->head == NULL)
    {
        list->tail = NULL;
    }

    command_t* command = temp->data;
    free(temp);
    return command;
    
}

void enqueue(list_t* list, command_t* item_adding)
{
    list_node_t* new_node = calloc(1, sizeof(list_node_t));
    new_node->data = item_adding;

    if(list->head == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    
}

void add_to_start_list(list_t* list, command_t* item_adding)
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
    scanf("%d", &num_to_delete);

    while(num_to_delete > *command_count)
    {
        printf("Choose number of commands to delete up to %d that are currently loaded\n", *command_count);
        scanf("%d", &num_to_delete);
    }


    for(int i = 0; i < num_to_delete; i++)
    {
        dequeue(list);
        (*command_count)--;
    }
    printf("Successfully deleted commands.\n");
}
    
