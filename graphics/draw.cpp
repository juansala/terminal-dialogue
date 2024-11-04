#include "terminal_dialogue/graphics/draw.hpp"

void ncurses_wrapper::initialize(bool one_char, bool no_echo, bool special_keys, 
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

void ncurses_wrapper::restore_terminal_settings()
{
  endwin();
}

int ncurses_wrapper::read_input()
{
  return getch();
}

void ncurses_wrapper::add_pixel_char(int x, int y, char pixel_type, Window* win_ptr, 
                    char attribute)
{
  // TODO(juansala): Handle character attributes.
  if (!win_ptr)
  {
    // No window given, write to `stdscr`
    mvaddch(y, x, pixel_type);
    refresh();
  }
  else
  {
    mvwaddch(win_ptr, y, x, pixel_type);
    wrefresh(win_ptr);
  }
}