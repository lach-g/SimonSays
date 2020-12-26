#include "list.h"
#include "asciiPrinting.h"

void enqueue(list_t* list, void* item_adding);
command_t* dequeue(list_t* list);
command_t* create_command_action(command_t* to_complete);
list_t* create_command_reference_list();
command_t* match_description_action(char* string, void(*action)());
