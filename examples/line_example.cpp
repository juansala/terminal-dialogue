#include "terminal_dialogue/graphics/geometry.hpp"

int main(int argc, char* argv[])
{
  ncurses_wrapper::initialize(true, true, true, true, false);
  Line line(0, 0, 15, 15, 'X', ncurses_wrapper::DefaultColorPairs::CLASSIC);
  line.draw();
  ncurses_wrapper::window_refresh();
  ncurses_wrapper::read_input();
  ncurses_wrapper::restore_terminal_settings();
  return 0;
}