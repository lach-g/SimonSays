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

void print_2_dance_phases(void (*phase1)(), void (*phase2)())
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
    }
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
   "     /   \\\n"
   "    |     |\n"
   "   -       -\n"
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
