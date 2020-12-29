#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "asciiPrinting.h"
#define STICK_REPEAT 5


/* Prints to terminal the 2 given frames manipulated to appear as moving images 
   by repeatably refreshing the terminal with new lines */
void animation(char* display_frame1, char* display_frame2)
{
    char* frame1 = malloc(FRAME_STRING_LEN * sizeof(char));
    char* frame2 = malloc(FRAME_STRING_LEN * sizeof(char));
    char* refresh = malloc(FRAME_STRING_LEN * sizeof(char));

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
    printf("%s", refresh);

    free(frame1);
    free(frame2);
 
    free(refresh);
}

/* Prints to terminal dancing frames using the animation function */
void dance()
{
    animation(DANCE1, DANCE2);
}

/* Prints to terminal left hand up frames using the animation function */
void left_wave()
{
    animation(LEFT_WAVE1, LEFT_WAVE2);
}

/* Prints to terminal right hand up frames using the animation function */
void right_wave()
{
    animation(RIGHT_WAVE1, RIGHT_WAVE2);
}

/* Prints to terminal touch head frames using the animation function */
void touch_head()
{
    animation(TOUCH_HEAD1, TOUCH_HEAD2);
}

/* Prints to terminal shaking head frames using the animation function */
void shake_head()
{
    animation(SHAKE_HEAD1, SHAKE_HEAD2);
}

/* Prints to terminal shrug frames using the animation function */
void shrug()
{
    animation(SHRUG1, SHRUG2);
}
