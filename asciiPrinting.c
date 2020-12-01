#include <stdio.h>
#include <unistd.h>
#define STICK_REPEAT 5

void print_stick_man()
{
    puts(
        " O\n"
        "/|\\\n"
        "/ \\\n");

}

void print_stick_man_wave()
{
   puts(
        " O\n"
        "/|/\n"
        "/ \\\n");
 
}

void print_dancing_stickman1()
{
    puts(
        " _O/\n"
        "   \\\n" 
        "   /\\_\n" 
        "   \\  `\n"
        "   `\n"
    );
}

void print_dancing_stickman2()
{
    puts(
            "    ,\n"
            " O/ /\n"   
            " /\\|/\\.\n"
    );
}

void print_dancing_stickman3()
{
    puts(
    "     ,\n"
    "    /\n"
    " `\\_\\\n"        
    "     \\\n"         
    "    /O\\\n" 
    );
}

void print_dancing_stickman4()
{
    puts(
      "    \\O_\n"
      " ,/\\/\n"
      "   /\n"
      "   \\\n"
      "   `\n"
    );
}

void print_4_dance_phases(void (*phase1)(), void (*phase2)(), void (*phase3)(), void (*phase4)())
{
    int i;
    for(i = 0; i < STICK_REPEAT; i++)
    {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        (*phase1)();
        usleep(250000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        (*phase2)();
        usleep(250000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        (*phase3)();
        usleep(250000);
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        (*phase4)();
        usleep(250000);
    }
}


