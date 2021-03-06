#include "list.h"
#include "asciiPrinting.h"

#define DESCRIPTION_FORMAT " %64[^\n]"


void enqueue(list_t* list, void* item_adding);
command_t* dequeue(list_t* list);
command_t* create_command_action(command_t* to_complete, const list_t* reference_commands);
list_t* create_command_reference_list();
command_t* match_description_action(const char* string, const Action_ptr action);
command_t* initiate_input_to_command(const list_t* reference_commands);
command_t* process_file_line_to_command(char* line, const list_t* reference_commands);
char* cut(char* line);
Action_ptr find_action_everything_mode(const char* description);
