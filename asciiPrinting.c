#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "list.h"
#include "asciiPrinting.h"
#define STICK_REPEAT 5


/* Prints to terminal the 2 given frames manipulated to appear as moving images */
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



/* Dancing frames to the animation function */
void dance()
{
    animation(DANCE1, DANCE2);
}

/* Left wave frames to the animation function */
void left_wave()
{
    animation(LEFT_WAVE1, LEFT_WAVE2);
}

/* Right wave frames to the animation function */
void right_wave()
{
    animation(RIGHT_WAVE1, RIGHT_WAVE2);
}

/* Touch head frames to the animation function */
void touch_head()
{
    animation(TOUCH_HEAD1, TOUCH_HEAD2);
}

/* Shake head frames to the animation function */
void shake_head()
{
    animation(SHAKE_HEAD1, SHAKE_HEAD2);
}

/* frames to the animation function */
void shrug()
{
    animation(SHRUG1, SHRUG2);
}








/* Left over Simon print statements for reference */
void simon()
{
    puts(
   "              ----------------------------\n" 
   "             |  Simon said touch my head  |\n" 
   "      ---    |     So I will touch it     |\n"
   "    /     \\ / ---------------------------\n"
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
