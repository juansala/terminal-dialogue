#include "terminal_dialogue/graphics/geometry.hpp"

int main(int argc, char* argv[]) {
  ncurses_wrapper::Initialize(true, true, true, true, false);
  Line line(0, 0, 15, 15, 'X', ncurses_wrapper::default_color_pairs::kClassic);
  line.Draw();
  ncurses_wrapper::WindowRefresh();
  ncurses_wrapper::ReadInput();
  ncurses_wrapper::RestoreTerminalSettings();
  return 0;
}