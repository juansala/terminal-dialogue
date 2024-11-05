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

  // TODO(juansala): Initialize new colors.
}

void ncurses_wrapper::restore_terminal_settings()
{
  endwin();
}

int ncurses_wrapper::read_input()
{
  return getch();
}

void ncurses_wrapper::add_pixel_char(int x, int y, unsigned int pixel_type, 
                                     const Color& color, Window* win_ptr, 
                                     unsigned int attribute)
{
  // TODO(juansala): Keep track of added colors to avoid doing this every pixel?
  init_color(8, color.r, color.g, color.b);
  init_pair(1, 8, 0);
  unsigned int pixel = pixel_type | COLOR_PAIR(1) | attribute;
  // TODO(juansala): Handle character attributes.
  if (!win_ptr)
  {
    // No window given, write to `stdscr`
    mvaddch(y, x, pixel);
    refresh();
  }
  else
  {
    mvwaddch(win_ptr, y, x, pixel);
    wrefresh(win_ptr);
  }
}