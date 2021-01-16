#include "list.h"
#include "input_checking.h"
#include "queue.h"

typedef enum
{
    ENTER_COMMANDS = 1,
    LOAD_FILE_COMMANDS = 2,
    DELETE_COMMANDS = 3,
    PLAY = 4,
    EXIT = 5
} Menu_options;

void cancel_choice(int* choice);
void menu(int* cont, list_t* list);
void display_options();
void enter_commands(list_t* list);
void play_actions(list_t* list);
void load_file_commands(list_t* list);





