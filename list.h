#ifndef HEADER_GUARD
#define HEADER_GUARD

#include <stdlib.h>
#define FR_STRING_LEN 300
#define COM_STRING_LEN 128

/* Pointer to animation functions */
typedef void (*Action_ptr)();


/* Command node structure */
typedef struct Command
{
    char description[COM_STRING_LEN];
    Action_ptr action;

} command_t;


/* Function declarators */
void printCommand(command_t* node);
command_t* createCommand();


#endif


