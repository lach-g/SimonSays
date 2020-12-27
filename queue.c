#include <string.h>
#include <stdio.h>
#include "queue.h"

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
    
}

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
    return command;
}

command_t* create_command_action(command_t* to_complete)
{
    char trick_command[COM_STRING_LEN];
    strcpy(trick_command, to_complete->description);
    trick_command[16] = '\0';

    char cut_input[COM_STRING_LEN];
    strcpy(cut_input, to_complete->description);
    cut_input[16] = '\0';

    list_t* command_refs = create_command_reference_list();

    int found;
    for(list_node_t* current = command_refs->head; current != NULL; current = current->next)
    {
       found = 0;
       command_t* command_ref = current->data;
       printf("to complete: %s compared to: %s\n", to_complete->description, command_ref->description);
       if(strcmp(to_complete->description, command_ref->description) == 0)
       {
           to_complete->action = command_ref->action;
           found = 1;
           break;
       }
       else if (strcmp(cut_input, trick_command) == 0)
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


list_t* create_command_reference_list()
{
    list_t* all_descriptions = create_list();
    
    command_t* dance_ref = match_description_action("Simon says dance", &dance);
    enqueue(all_descriptions, dance_ref);

    command_t* left_wave_ref = match_description_action("Simon says left hand up", &left_wave);
    enqueue(all_descriptions, left_wave_ref);

    command_t* right_wave_ref = match_description_action("Simon says right hand up", &right_wave);
    enqueue(all_descriptions, right_wave_ref);

    command_t* touch_head_ref = match_description_action("Simon says hands on head", &touch_head);
    enqueue(all_descriptions, touch_head_ref);

    command_t* didnt_say_ref = match_description_action("Simon didn't say", &shake_head);
    enqueue(all_descriptions, didnt_say_ref);
    
    return all_descriptions;
}

command_t* match_description_action(char* string, void(*action)())
{
    command_t* command = malloc(1*sizeof(command_t));
    strcpy(command->description, string);
    command->action = action;
    return command;
}
