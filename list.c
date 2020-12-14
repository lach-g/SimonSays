#include "list.h"

list_t* create_list()
{
    return calloc(1, sizeof(list_t));
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
    
