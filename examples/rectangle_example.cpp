#include "terminal_dialogue/graphics/rectangle.hpp"

int main(int argc, char* argv[])
{
  initialize_ncurses(true, true, true, true);
  Rectangle rect(5, 5, 'A', 5, 5);
  rect.draw();
  read_input();
  restore_terminal_settings();
  return 0;
}