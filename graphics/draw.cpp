#include "terminal_dialogue/graphics/draw.hpp"

void initialize_ncurses(bool one_char, bool no_echo, bool special_keys, 
                        bool use_color)
{
  initscr();
  if (one_char)
    cbreak();
  if (no_echo)
    noecho();
  if (special_keys)
    keypad(stdscr, true);
  if (use_color)
    start_color();

  // TODO(juansala): Handle multiple windows beyond `stdscr` and multiple
  // terminals.
}

void restore_terminal_settings()
{
  endwin();
}

void add_pixel_char(int x, int y, char pixel_type, char attribute)
{
  // TODO(juansala): Handle character attributes.
  mvaddch(y, x, pixel_type);
  refresh();
}