#include "terminal_dialogue/graphics/ncurses_wrapper.hpp"

void ncurses_wrapper::Initialize(bool one_char, bool no_echo, bool special_keys, 
                                 bool use_color, bool no_delay) {
  initscr();
  if (one_char)
    cbreak();
  if (no_echo)
    noecho();
  if (special_keys)
    keypad(stdscr, true);
  if (use_color) {
    start_color();
    InitializePairs();
  }

  nodelay(stdscr, no_delay);
  curs_set(0); // TODO(juansala): Handle hiding cursor. 

  // TODO(juansala): Handle enabling special keys.

  // TODO(juansala): Handle multiple windows beyond `stdscr` and multiple
  // terminals.
}

void ncurses_wrapper::InitializePairs() {
  for (auto& pair : default_color_pairs::kPairs) {
    init_pair(pair.id, pair.foreground.id, pair.background.id);
  }
}

void ncurses_wrapper::WindowRefresh(WindowSharedPtr win_ptr) {
  if (!win_ptr)
    refresh();
  else
    wrefresh(win_ptr.get());
}

void ncurses_wrapper::WindowClear(WindowSharedPtr win_ptr) {
  if (!win_ptr)
    erase();
  else
    werase(win_ptr.get());
}

void ncurses_wrapper::RestoreTerminalSettings() {
  endwin();
}

int ncurses_wrapper::ReadInput() {
  return getch();
}

void ncurses_wrapper::AddPixelChar(int x, int y, unsigned int pixel_type, 
                                     ncurses_wrapper::ColorPair color_pair, 
                                     WindowSharedPtr win_ptr, 
                                     unsigned int attribute) {
  unsigned int pixel = pixel_type | COLOR_PAIR(color_pair.id) | attribute;
  // TODO(juansala): Handle character attributes.
  if (!win_ptr) {
    // No window given, write to `stdscr`
    mvaddch(y, x, pixel);
    // refresh(); // Need this refresh here?
  }
  else {
    mvwaddch(win_ptr.get(), y, x, pixel);
    // wrefresh(win_ptr); // Need this refresh here?
  }
}