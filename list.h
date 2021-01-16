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
    struct LinkedList* reference_commands;
} list_t;

void read_file_to_queue(const char* filename, list_t* list);
list_t* create_user_list();
list_t* create_a_list();
void add_to_start_list(list_t* list, void* item_adding);
void print_list(list_t* list);
void free_list(list_t* list);
void delete_items(list_t* list);
void delete_message(const int* total_deleted);
void free_list(list_t* list);
void free_a_list(list_t* list);


#endif

