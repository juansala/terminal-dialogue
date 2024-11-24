#include "terminal_dialogue/graphics/renderer.hpp"

int main(int argc, char* argv[])
{
  ncurses_wrapper::initialize(true, true, true, true, false);

  std::vector<Geometry::SharedPtr> elements;
  for (int i = 0; i <= 5; i++)
  {
    elements.push_back(std::make_shared<Rectangle>(0, 5*i, '*', 3, 3));
  }

  Renderer renderer;
  renderer.draw(elements);
  
  ncurses_wrapper::window_refresh();
  ncurses_wrapper::read_input();
  ncurses_wrapper::restore_terminal_settings();
}