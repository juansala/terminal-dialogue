#include <chrono>
#include <thread>

#include "terminal_dialogue/graphics/frame.hpp"
#include "terminal_dialogue/graphics/shape.hpp"
#include "terminal_dialogue/graphics/rectangle.hpp"

int main(int argc, char* argv[])
{
  ncurses_wrapper::initialize(true, true, true, true, true);

  std::vector<Geometry::SharedPtr> elements;
  auto rect_ptr = std::make_shared<Rectangle>(0, 0, '*', 5, 5);
  elements.push_back(rect_ptr);
  Frame frame(elements);
  frame.draw();

  int i = 0;
  while(ncurses_wrapper::read_input() == ncurses_wrapper::InputKeys::NONE)
  {
    for (auto geom : elements)
    {
      geom->set_origin(i++, 0);
    }
    ncurses_wrapper::window_clear();
    frame.draw();
    ncurses_wrapper::window_refresh();
    if (i == 100) i = 0;
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
  }

  ncurses_wrapper::read_input();
  ncurses_wrapper::restore_terminal_settings();
}