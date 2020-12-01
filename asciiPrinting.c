#include <stdio.h>
#include <unistd.h>
#define STICK_REPEAT 5

void dancing_stickman1()
{
    /*
    puts(
        " _O/\n"
        "   \\\n" 
        "   /\\_\n" 
        "   \\  `\n"
        "   `\n"
    );
    */
    char* figure1 = "\n _O/\n   \\\n   /\\_\n   \\  `\n   `\n";
    printf("%s", figure1);

}

void dancing_stickman2()
{
    puts(
            "    ,\n"
            " O/ /\n"   
            " /\\|/\\.\n"
    );
}

void dancing_stickman3()
{
    puts(
    "     ,\n"
    "    /\n"
    " `\\_\\\n"        
    "     \\\n"         
    "    /O\\\n" 
    );
}

void dancing_stickman4()
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

void simon()
{
    puts(
    
         ----
       /      \\
      |        |
      |        |
       \\     /
    
    );

}


