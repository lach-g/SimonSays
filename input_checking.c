#include <stdlib.h>
#include <stdio.h>
#include "input_checking.h"

/* Prints runtime usage instructions to terminal */
void too_many_args()
{
    printf("Too many command line arguments provided\n");
    printf("Run either with zero or one filename to read in.\n");
}

/* Scans for user input and returns as integer or zero if not */
int scan_for_int()
{
    char check_input[INPUT_STRING_LEN];
    int converted_input;

    scanf("%8s",check_input);
    converted_input = atoi(check_input);
    if(converted_input)
    {
        return converted_input;
    }
    else
    {
        return 0;
    }
}

/* Processes the runtime filename inputted for .txt extension
   reading it's lines into the linked list */
void process_file_input(list_t* list, char** input_array)
{
    char filename[FILE_STRING_LEN];
    scan_for_filename(input_array, filename);
    if(has_txt_extension(filename))
    {
        read_file_to_queue(filename, list);
    }
    else
    {
        printf("Not the proper extension\n");
    }
}

