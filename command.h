#ifndef HEADER_GUARD
#define HEADER_GUARD

#include <stdlib.h>
#define FR_STRING_LEN 300
#define COM_STRING_LEN 128
#define FILE_STRING_LEN 64

/* Pointer to animation functions */
typedef void (*Action_ptr)();

/* Command node structure */
typedef struct Command
{
    char description[COM_STRING_LEN];
    Action_ptr action;

} command_t;


/* Function declarators */
void scan_input(int* arg_count, char* argv[], char* filename, int* input);
void printCommand(command_t* node);
command_t* create_command_descript();
command_t* create_command_action(command_t* to_complete);
command_t* create_file_command(char* line);


#endif


