#include <chrono>
#include <thread>

#include "terminal_dialogue/graphics/renderer.hpp"
#include "terminal_dialogue/graphics/rectangle.hpp"
#include "terminal_dialogue/utils/timer.hpp"

int main(int argc, char* argv[])
{
  ncurses_wrapper::initialize(true, true, true, true, true);

  double frame_rate = 60.0;
  Timer::SharedPtr timer_ptr = std::make_shared<Timer>();

  std::vector<Geometry::SharedPtr> elements;
  auto rect_ptr = std::make_shared<Rectangle>(0, 0, '*', 5, 5);
  elements.push_back(rect_ptr);
  Renderer renderer;

  while (ncurses_wrapper::read_input() == ncurses_wrapper::InputKeys::NONE)
  {
    timer_ptr->tick();
    if (timer_ptr->get_time() >= 1/frame_rate)
    {
      for (auto geom : elements)
      {
        geom->set_origin(geom->get_x() + 1, 0.0);
      }
      ncurses_wrapper::window_clear();
      renderer.draw(elements);
      ncurses_wrapper::window_refresh();
      timer_ptr->reset();
    }
  }

  ncurses_wrapper::read_input();
  ncurses_wrapper::restore_terminal_settings();
}