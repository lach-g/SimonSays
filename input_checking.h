#include "command.h"
#include "list.h"

#define INPUT_FORMAT "%8s"

void scan_for_filename(const char* argv[], char* filename);
void too_many_args();
int scan_for_int();
void process_file_input(list_t* list, const char** input_array);
