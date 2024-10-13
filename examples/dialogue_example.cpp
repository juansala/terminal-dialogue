#include <ncurses.h>
#include "entity.h"

// Simple example which demonstrates simple animated dialogue text using the
// Entity class.
// TODO(juansala): Wrap the common ncurses function calls into a convenient
// function or class (maybe ScreenManager?).

int main(int argc, char* argv[])
{
  initscr();
  noecho();
  cbreak();
  refresh();

  start_color();
  use_default_colors();
  init_pair(1, 6, -1);

  int red = COLOR_PAIR(1);
  std::string e1_name = "Entity 1";
  Entity e1{e1_name, 300, red, 500};
  std::string e1_msg = "I am alive! Check me out! I am ... pausing, almost whenever I want. What do you think?";
  int xy[2] {0, 0};
  e1.speak(stdscr, xy, e1_msg, false);

  std::string return_msg = "Press any key to continue...";
  e1.set_color(COLOR_PAIR(0));
  int new_loc[2] {5, 0};
  e1.speak(stdscr, new_loc, return_msg, true);
  getch();
  endwin();
  return 0;
}