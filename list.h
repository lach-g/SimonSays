#ifndef HEADER_GUARD
#define HEADER_GUARD

#define STRING_LEN 128

/* Pointer to printer function that takes in two function pointer that print a phase of simon */
typedef void (*Action_ptr)(void (*phase1)(), void (*phase2)());

typedef struct Command
{
    char description[STRING_LEN];
    Action_ptr print_action;

} command_t;

#endif


