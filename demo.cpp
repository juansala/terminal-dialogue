#include <iostream>
#include "dialog.h"
#include <ncurses.h>
/* 

TODO:
- Entity for narration/announcements, then for individual characters?
*/


int main(int argc, char* argv[])
{
    initscr();
    noecho();
    refresh();

    start_color();
    init_pair(1,1,0);

    int red[3] = {255, 0, 0};
    std::string e1_name = "Entity 1";
    Entity e1{e1_name, 300, red, 500};
    std::string e1_msg = "I am alive! Check me out! I am ... pausing, almost whenever I want. What do you think?";
    e1.speak(stdscr, e1_msg);

    move(5, 0);
    addstr("Press any key to continue...");
    getch();
    endwin();
    return 0;
}