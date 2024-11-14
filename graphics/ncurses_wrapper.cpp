#include "terminal_dialogue/graphics/ncurses_wrapper.hpp"

void ncurses_wrapper::initialize(bool one_char, bool no_echo, bool special_keys, 
                                 bool use_color, bool no_delay)
{
  initscr();
  if (one_char)
    cbreak();
  if (no_echo)
    noecho();
  if (special_keys)
    keypad(stdscr, true);
  if (use_color)
  {
    start_color();
    initialize_pairs();
  }

  nodelay(stdscr, no_delay);
  curs_set(0); // TODO(juansala): Handle hiding cursor. 

  // TODO(juansala): Handle enabling special keys.

  // TODO(juansala): Handle multiple windows beyond `stdscr` and multiple
  // terminals.
}

void ncurses_wrapper::initialize_pairs()
{
  for (auto& pair : DefaultColorPairs::pairs)
  {
    init_pair(pair.id, pair.foreground.id, pair.background.id);
  }
}

void ncurses_wrapper::window_refresh(Window* win_ptr)
{
  if (!win_ptr)
    refresh();
  else
    wrefresh(win_ptr);
}

void ncurses_wrapper::window_clear(Window* win_ptr)
{
  if (!win_ptr)
    erase();
  else
    werase(win_ptr);
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
                                     ncurses_wrapper::ColorPair color_pair, 
                                     Window* win_ptr, unsigned int attribute)
{
  unsigned int pixel = pixel_type | COLOR_PAIR(color_pair.id) | attribute;
  // TODO(juansala): Handle character attributes.
  if (!win_ptr)
  {
    // No window given, write to `stdscr`
    mvaddch(y, x, pixel);
    // refresh(); // Need this refresh here?
  }
  else
  {
    mvwaddch(win_ptr, y, x, pixel);
    // wrefresh(win_ptr); // Need this refresh here?
  }
}