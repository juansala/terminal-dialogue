#include "terminal_dialogue/graphics/renderer.hpp"

int main(int argc, char* argv[]) {
  ncurses_wrapper::Initialize(true, true, true, true, false);

  std::vector<Geometry::SharedPtr> elements;
  for (int i = 0; i <= 5; i++) {
    elements.push_back(std::make_shared<Rectangle>(0, 5*i, '*', 3, 3));
  }

  Renderer renderer;
  renderer.Draw(elements);
  
  ncurses_wrapper::WindowRefresh();
  ncurses_wrapper::ReadInput();
  ncurses_wrapper::RestoreTerminalSettings();
}