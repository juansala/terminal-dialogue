#include "terminal_dialogue/graphics/rectangle.hpp"

int main(int argc, char* argv[])
{
  ncurses_wrapper::initialize(true, true, true, true);
  Rectangle rect(0, 0, 'X', 5, 5);
  rect.draw();
  ncurses_wrapper::read_input();
  ncurses_wrapper::restore_terminal_settings();
  return 0;
}