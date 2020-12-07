#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "list.h"
#include "asciiPrinting.h"
#define STICK_REPEAT 5


void animation(char* display_frame1, char* display_frame2)
{
    char* frame1 = malloc(STRING_LEN * sizeof(char));
    char* frame2 = malloc(STRING_LEN * sizeof(char));
    char* refresh = malloc(STRING_LEN * sizeof(char));

    strcpy(frame1, display_frame1);
    strcpy(frame2, display_frame2);
    strcpy(refresh, REFRESH);

    int i;
    for(i = 0; i < STICK_REPEAT; i++)
    {
        printf("%s", refresh);
        printf("%s", frame1);
        usleep(250000);
        printf("%s", refresh);
        printf("%s", frame2);
        usleep(250000);
    }

    free(frame1);
    free(frame2);
 
    free(refresh);
}



/* Simon dancing function */
void dance()
{
    animation(DANCE1, DANCE2);
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
   "              ----------------------------\n" 
   "             | Simon said left hand wave! |\n" 
   "      ---    |      So I will WAVE        |\n"
   "    /     \\ / ----------------------------\n"
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
    


   "              ----------------------------\n" 
   "             | Simon said left hand wave! |\n" 
   "      ---    |      So I will WAVE        |\n"
   "    /     \\ / ----------------------------\n"
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
    



   "              -----------------------------\n" 
   "             | Simon said right hand wave! |\n" 
   "      ---    |        So I will WAVE       |\n"
   "    /     \\ / ----------------------------\n"
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



    
   "              ----------------------------\n" 
   "             |  Simon said touch my head  |\n" 
   "      ---    |     So I will touch it     |\n"
   "    /     \\ / ---------------------------\n"
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


    
   "               ----------------------------\n" 
   "              |  Not a Simon Says command! |\n" 
   "     ---    /  ----------------------------\n"
   "   /     \\/\n"
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
   "               ----------------------------\n" 
   "              |  Not a Simon Says command! |\n" 
   "        --- /  ----------------------------\n"
   "      /     \\\n"
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

void simon_shrug1()
{
    puts(
    
   "             ------------------------------------\n" 
   "            |  Simon doesn't know how to do that |\n" 
   "      ---  / ------------------------------------\n"
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

void simon_shrug2()
{
    puts(
   "             ------------------------------------\n" 
   "            |  Simon doesn't know how to do that |\n" 
   "      ---  / ------------------------------------\n"
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


















/* Old Simon functions for viewing reference */
void simon_dances1()
{
    puts(
   "              -------------------\n"     
   "             | Simon says dance! |\n"     
   "      ---    | So I will DANCE   |\n"
   "    /     \\ / -------------------\n"
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
    
   "              -------------------\n"     
   "             | Simon says dance! |\n"     
   "      ---    | So I will DANCE   |\n"
   "    /     \\ / -------------------\n"
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
