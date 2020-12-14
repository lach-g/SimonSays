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

list_t* create_list();
void add_to_start_list(list_t* list, command_t* item_adding);
void print_list(list_t* list);
void free_list(list_t* list);
command_t* dequeue(list_t* list);
void enqueue(list_t* list, command_t* item_adding);



