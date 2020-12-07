#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "list.h"
#define STICK_REPEAT 5

/* Simon dancing function */
void dance()
{
    char* phase1 = malloc(STRING_LEN * sizeof(char));
    char* phase2 = malloc(STRING_LEN * sizeof(char));
    char* refresh = malloc(STRING_LEN * sizeof(char));

    strcpy(phase1, "      ---\n    /     \\\n   | 0   0 |\n   |   ^   |\n _  \\__V__/\n  \\    |\n    ---|---\n       |    \\\n      / \\    -\n      \\ /\n      / \\\n     -   -\n\0");
    strcpy(phase2, "      ---\n    /     \\\n   | 0   0 |\n   |   ^   |\n    \\__V__/  _\n       |    /\n    ---|---\n   /   |      \n -    / \\     \n     /   \\\n    |     |\n   -       -\n\0");
    strcpy(refresh, "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    int i;
    for(i = 0; i < STICK_REPEAT; i++)
    {
        printf("%s", refresh);
        printf("%s", phase1);
        usleep(250000);
        printf("%s", refresh);
        printf("%s", phase2);
        usleep(250000);
    }

    free(phase1);
    free(phase2);
    
    free(refresh);
}

void right_wave()
{
    char phase1[STRING_LEN] = "      ---\n    /     \\\n   | 0   0 |\n   |   ^   |\n    \\__V__/\n       |\n ------|------\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n";
    char phase2[STRING_LEN] = "      ---\n    /     \\\n   | 0   0 |\n   |   ^   |\n\\   \\__V__/\n \\     |   \n   ----|------\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n";
    char refresh[STRING_LEN] = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    int i;
    for(i = 0; i < STICK_REPEAT; i++)
    {
        printf("%s", refresh);
        printf("%s", phase1);
        usleep(250000);
        printf("%s", refresh);
        printf("%s", phase2);
        usleep(250000);
    }
    printf("%s", refresh);
}



void simon()
{
    puts(
    
   "      ---\n"
   "    /     \\\n"
   "   | 0   0 |\n"
   "   |   ^   |\n"
   "    \\__V__/\n"
   "       |\n"
   " ------|------\n"
   "       |\n"
   "      / \\\n"
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
    );

}

void simon_left_hand()
{
    puts(
    
   "      ---\n"
   "    /     \\\n"
   "   | 0   0 |\n"
   "   |   ^   |\n"
   "    \\__V__/  /\n"
   "       |    /\n"
   " ------|---\n"
   "       |\n"
   "      / \\\n"
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
    );
}

void simon_right_hand()
{
    puts(
    
   "      ---\n"
   "    /     \\\n"
   "   | 0   0 |\n"
   "   |   ^   |\n"
   "\\   \\__V__/\n"
   " \\     |   \n"
   "   ----|------\n"
   "       |\n"
   "      / \\\n"
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
    );
}

void simon_touches_head()
{
   puts(
    
   "      ---\n"
   "    /     \\\n"
   "  ,| 0   0 |,\n"
   " / |   ^   | \\\n"
   " \\  \\__V__/  /\n"
   "  \\    |    / \n"
   "    ---|---\n"
   "       |\n"
   "      / \\\n"
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
    ); 
}



void simon_shakes_head1()
{
   puts(
    
   "     --\n"
   "   /    \\\n"
   "  | 0  0 |\n"
   "  |  ^   |\n"
   "   \\_V_/\n"
   "       |     /\n"
   " ------|-----\n"
   "       |\n"
   "      / \\\n"
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
    ); 
}

void simon_shakes_head2()
{
   puts(
    
   "        ---\n"
   "      /    \\\n"
   "     | 0  0 |\n"
   "     |   ^  |\n"
   "       \\_V_/\n"
   "       |     \\\n"
   " ------|-----\n"
   "       |\n"
   "      / \\\n"
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
    ); 
}

void simon_shrug()
{
    puts(
    
   "      ---\n"
   "    /     \\\n"
   "   | 0   0 |\n"
   "   |   ^   |\n"
   "  - \\__V__/ -\n"
   "   \\   |   /\n"
   "    ---|---\n"
   "       |\n"
   "      / \\\n"
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
    );
}


















/* Old Simon functions for viewing reference */
void simon_dances1()
{
    puts(
    
   "      ---\n"
   "    /     \\\n"
   "   | 0   0 |\n"
   "   |   ^   |\n"
   " _  \\__V__/\n"
   "  \\    |\n"
   "    ---|---\n"
   "       |    \\\n"
   "      / \\    -\n"
   "      \\ /\n"
   "      / \\\n"
   "     -   -\n"
    );
}

void simon_dances2()
{
    puts(
    
   "      ---\n"
   "    /     \\\n"
   "   | 0   0 |\n"
   "   |   ^   |\n"
   "    \\__V__/  _\n"
   "       |    /\n"
   "    ---|---\n"
   "   /   |      \n"
   " -    / \\     \n"
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
    );
}
