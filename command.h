#ifndef HEADER_GUARD
#define HEADER_GUARD

#include <stdlib.h>
#include "list.h"

#define FRAME_STRING_LEN 317
#define COMMAND_STRING_LEN 64
#define FILE_STRING_LEN 32
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

int has_txt_extension(const char* filename);
void print_command(const command_t* node);

#endif


