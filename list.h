#ifndef HEADER_GUARD2
#define HEADER_GUARD2

#include "command.h"
typedef struct ListNode
{
    void* data;
    struct ListNode* next;
} list_node_t;

typedef struct LinkedList
{
    list_node_t* head;
    list_node_t* tail;
    int count;
} list_t;

void process_input(char* filename, list_t* list, int* input, int* track_commands);
void read_file_to_queue(char* filename, list_t* list, int* track_commands);
list_t* create_list();
void add_to_start_list(list_t* list, command_t* item_adding);
void print_list(list_t* list);
void free_list(list_t* list);
command_t* dequeue(list_t* list);
void enqueue(list_t* list, command_t* item_adding);
void delete_items(list_t* list, int* command_count);

#endif


