#ifndef HEADER_GUARD
#define HEADER_GUARD

#include <stdlib.h>
#include "list.h"
#define FRAME_STRING_LEN 300
#define COMMAND_STRING_LEN 128
#define FILE_STRING_LEN 64
#define INPUT_STRING_LEN 8

/* Pointer to animation functions */
typedef void (*Action_ptr)();

/* Command node structure to contain the description of the simon says command
   and a function pointer to the corresponding action */
typedef struct Command
{
    char description[COMMAND_STRING_LEN];
    Action_ptr action;

} command_t;

void scan_for_filename(char* argv[], char* filename);
int has_txt_extension(char* filename);
void print_command(command_t* node);

#endif


