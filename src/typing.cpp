#include <iostream>
#include <ncurses.h>

#include "game.h"
#include "entity.h"
/* 

TODO:
- Entity for narration/announcements, then for individual characters?
*/


int main(int argc, char* argv[])
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, true);
    refresh();

    start_color();
    use_default_colors();
    init_pair(1, 6, -1);
    init_pair(2, 1, -1);
    Entity stream;
    stream.set_color(COLOR_PAIR(1));
    Game::GameState state = Game::GAME_CONTROL;
    std::string game_msg = "";
    game_msg = "This is a test message.";
    char ch{0};
    int input_idx = 0;
    int line_pos[2] = {0, 0};
    int cursor_x = 0; // TODO: Add as a Game member.
    int cursor_y = 0; // TODO: Add as a Game member.
    while (input_idx < game_msg.length())
    {
        if (state == Game::GAME_CONTROL)
        {
            stream.speak(stdscr, line_pos, game_msg, true);  
            state = Game::PLAYER_CONTROL;
            move(line_pos[0], line_pos[1]);
        }
        else if (state == Game::PLAYER_CONTROL)
        {
            if ((ch = getch()) != ERR)
            {
                
                if (ch != game_msg[input_idx])
                {
                    getyx(stdscr, cursor_y, cursor_x);
                    addch(game_msg[input_idx] | COLOR_PAIR(2));
                    move(cursor_y, cursor_x);
                    continue;
                }
                addch(ch | COLOR_PAIR(1));
                input_idx++;
            }
        }
    }
    endwin();
    return 0;
}