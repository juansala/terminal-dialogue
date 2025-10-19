#include "terminal_dialogue/graphics/rectangle.hpp"

int main(int argc, char* argv[]) {
  ncurses_wrapper::Initialize(true, true, true, true, false);
  Rectangle rect(0, 0, '.', 5, 5, 
                 ncurses_wrapper::default_color_pairs::kClassicGreen,  
                 ncurses_wrapper::default_color_pairs::kClassic);
  rect.Draw();
  ncurses_wrapper::WindowRefresh();
  ncurses_wrapper::ReadInput();
  ncurses_wrapper::RestoreTerminalSettings();
  return 0;
}