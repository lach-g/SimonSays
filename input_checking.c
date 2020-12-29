#include <stdlib.h>
#include <stdio.h>
#include "input_checking.h"

void too_many_args()
{
    printf("Too many command line arguments provided\n");
    printf("Run either with zero or one filename to read in.\n");
}

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

