#include <iostream>
#include <ncurses.h>

#include "game.h"
#include "entity.h"
#include "player.h"
/* 

TODO:
- Entity for narration/announcements, then for individual characters?
*/

int main(int argc, char* argv[])
{
    Game typing_game;
    typing_game.run();
    return 0;
}