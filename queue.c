#include <string.h>
#include <stdio.h>
#include "queue.h"

#define DESCRIPTION_FORMAT " %64[^\n]"


/* Adds any kind of pointer to the back of the linked list */
void enqueue(list_t* list, void* item_adding)
{
    list_node_t* new_node = calloc(1, sizeof(list_node_t));
    new_node->data = item_adding;

    if(list->head == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->count++;
    
}

/* Pops the first node in the list from the front of the queue
   and returns it */
command_t* dequeue(list_t* list)
{
    list_node_t* temp = list->head;
    list->head = list->head->next;

    if(list->head == NULL)
    {
        list->tail = NULL;
    }

    command_t* command = temp->data;
    free(temp);
    list->count--;
    return command;
}

/* Matches a command description with the corresponding action
   by looping through the reference commands to check for a match
   also conditional compilation allows for everything mode with only
   the action part of the description looked at */
command_t* create_command_action(command_t* to_complete, const list_t* reference_commands)
{
    char cut_input[COMMAND_STRING_LEN];
    strcpy(cut_input, to_complete->description);
    cut_input[16] = '\0';

    int found;
    for(list_node_t* current = reference_commands->head; current != NULL; current = current->next)
    {
        found = 0;
        #ifdef EVERYTHING
        Action_ptr action_match = find_action_everything_mode(to_complete->description);
        to_complete->action = action_match;
        found = 1;
        break;
        #endif

        command_t* command_ref = current->data;
        if(strcmp(to_complete->description, command_ref->description) == 0)
        {
            to_complete->action = command_ref->action;
            found = 1;
            break;
        }
        else if (strcmp(cut_input, "Simon didn't say") == 0)
        {
            to_complete->action = &shake_head;
            found = 1;
            break;
        }
    }
    if(!found)
    {
        to_complete->action = &shrug;
    }
    return to_complete;
}

/* Creating a reference list of possible input commands that can be matched returning
   a linked list */
list_t* create_command_reference_list()
{
    list_t* all_descriptions = create_a_list();
    
    command_t* dance_ref = match_description_action("Simon says dance", &dance);
    enqueue(all_descriptions, dance_ref);

    command_t* left_wave_ref = match_description_action("Simon says left hand up", &left_wave);
    enqueue(all_descriptions, left_wave_ref);

    command_t* right_wave_ref = match_description_action("Simon says right hand up", &right_wave);
    enqueue(all_descriptions, right_wave_ref);

    command_t* touch_head_ref = match_description_action("Simon says hands on head", &touch_head);
    enqueue(all_descriptions, touch_head_ref);
    
    return all_descriptions;
}

/* Allocates heap space to a new command and inserts the string and action into the command struct
   returning the new command pointer */
command_t* match_description_action(const char* string, const Action_ptr action)
{
    command_t* command = malloc(1*sizeof(command_t));
    strcpy(command->description, string);
    command->action = action;
    return command;
}

/* Parsing an input command and if conditional compilation is everything
   command description is cut to only include action portion */
command_t* initiate_input_to_command(const list_t* reference_commands)
{

    command_t* command = malloc(1*sizeof(command_t));

    printf("Enter command:\n");
    scanf(DESCRIPTION_FORMAT, command->description);

    #ifdef EVERYTHING
    char* cut_command = cut(command->description);
    strcpy(command->description, cut_command);
    #endif

    create_command_action(command, reference_commands);
    return command;    
}

command_t* process_file_line_to_command(char* line, const list_t* reference_commands)
{
    command_t* command = malloc(1*sizeof(command_t));
    line[strlen(line)] = '\0';

    #ifdef EVERYTHING
    line = cut(line);
    #endif

    strcpy(command->description, line);
    create_command_action(command, reference_commands);
    return command;
}

/* Cuts off the Simon does or doesn't say portion and returns action
   unless not matched where it returns the whole line */
char* cut(char* line)
{
    char simon_said_test[COMMAND_STRING_LEN];
    strcpy(simon_said_test, line);
    simon_said_test[10] = '\0';

    char simon_didnt_test[COMMAND_STRING_LEN];
    strcpy(simon_didnt_test, line);
    simon_didnt_test[16] = '\0';
    char* action_string;

    if(strcmp(simon_said_test, "Simon says") == 0)
    {
        action_string = &line[11];
    }
    else if(strcmp(simon_didnt_test, "Simon didn't say") == 0)
    {
        action_string = &line[17];
    }    
    else
    {
        action_string = &line[0];
    }
    
    return action_string;
}

/* Returns an action pointer that matches the description taken in
   returning a shrug if not */
Action_ptr find_action_everything_mode(const char* description)
{
    Action_ptr matched_action;

    if(strcmp(description, "dance") == 0)
    {
        matched_action = &dance;
    }
    else if(strcmp(description, "left hand up") == 0)
    {
        matched_action = &left_wave;
    }
    else if(strcmp(description, "right hand up") == 0)
    {
        matched_action = &right_wave;
    }
    else if(strcmp(description, "touch head") == 0)
    {
        matched_action = &touch_head;
    }
    else
    {
        matched_action = &shrug;
    }
    return matched_action;
}
