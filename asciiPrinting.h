#include "command.h"

#define DANCE1 "              -------------------\n             | Simon says dance! |\n      ---    | So I will DANCE   |\n    /     \\ / -------------------\n   | 0   0 |\n   |   ^   |\n _  \\__V__/\n  \\    |\n    ---|---\n       |    \\\n      / \\    -\n      \\ /\n      / \\\n     -   -\n\0"
#define DANCE2 "              -------------------\n             | Simon says dance! |\n      ---    | So I will DANCE   |\n    /     \\ / -------------------\n   | 0   0 |\n   |   ^   |\n    \\__V__/  _\n       |    /\n    ---|---\n   /   |      \n -    / \\     \n     /   \\\n    |     |\n   -       -\n\0"
#define LEFT_WAVE1 "              ----------------------------\n             | Simon said left hand wave! |\n      ---    |      So I will WAVE        |\n    /     \\ / ----------------------------\n   | 0   0 |\n   |   ^   |\n    \\__V__/\n       |\n ------|------\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define LEFT_WAVE2 "              ----------------------------\n             | Simon said left hand wave! |\n      ---    |      So I will WAVE        |\n    /     \\ / ----------------------------\n   | 0   0 |\n   |   ^   |\n    \\__V__/  /\n       |    /\n ------|---\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define RIGHT_WAVE1 "              -----------------------------\n             | Simon said right hand wave! |\n      ---    |        So I will WAVE       |\n    /     \\ / ----------------------------\n   | 0   0 |\n   |   ^   |\n    \\__V__/\n       |\n ------|------\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define RIGHT_WAVE2 "              -----------------------------\n             | Simon said right hand wave! |\n      ---    |        So I will WAVE       |\n    /     \\ / ----------------------------\n   | 0   0 |\n   |   ^   |\n\\   \\__V__/\n \\     |   \n   ----|------\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define TOUCH_HEAD1 "              ----------------------------\n             |  Simon said touch my head  |\n      ---    |     So I will touch it     |\n    /     \\ / ---------------------------\n   | 0   0 |\n   |   ^   |\n    \\__V__/\n       |\n ------|------\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define TOUCH_HEAD2 "              ----------------------------\n             |  Simon said touch my head  |\n      ---    |     So I will touch it     |\n    /     \\ / ---------------------------\n  ,| 0   0 |,\n / |   ^   | \\\n \\  \\__V__/  /\n  \\    |    / \n    ---|---\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define SHAKE_HEAD1 "               ----------------------------\n              |  Not a Simon Says command! |\n     ---    /  ----------------------------\n   /     \\/\n  | 0  0 |\n  |  ^   |\n   \\_V_/\n       |     /\n ------|-----\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define SHAKE_HEAD2 "               ----------------------------\n              |  Not a Simon Says command! |\n        --- /  ----------------------------\n      /     \\\n     | 0  0 |\n     |   ^  |\n       \\_V_/\n       |     \\\n ------|-----\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define SHRUG1 "             ------------------------------------\n            |  Simon doesn't know how to do that |\n      ---  / ------------------------------------\n    /     \\\n   | 0   0 |\n   |   ^   |\n  - \\__V__/ -\n   \\   |   /\n    ---|---\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define SHRUG2 "             ------------------------------------\n            |  Simon doesn't know how to do that |\n      ---  / ------------------------------------\n    /     \\\n   | 0   0 |\n   |   ^   |\n    \\__V__/\n       |\n ------|------\n       |\n      / \\\n     /   \\\n    |     |\n   -       -\n"
#define REFRESH "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"

void animation(char* display_frame1, char* display_frame2);
void dance();
void left_wave();
void right_wave();
void touch_head();
void shake_head();
void shrug();
