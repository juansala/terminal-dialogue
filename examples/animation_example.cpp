#include <chrono>
#include <thread>

#include "terminal_dialogue/graphics/renderer.hpp"
#include "terminal_dialogue/graphics/rectangle.hpp"
#include "terminal_dialogue/utils/timer.hpp"

int main(int argc, char* argv[]) {
  ncurses_wrapper::Initialize(true, true, true, true, true);

  double frame_rate = 60.0;
  Timer::SharedPtr timer_ptr = std::make_shared<Timer>();

  std::vector<Geometry::SharedPtr> elements;
  auto rect_ptr = std::make_shared<Rectangle>(0, 0, '*', 5, 5);
  elements.push_back(rect_ptr);
  Renderer renderer;

  while (ncurses_wrapper::ReadInput() == ncurses_wrapper::input_keys::kNone) {
    timer_ptr->Tick();
    if (timer_ptr->GetTime() >= 1/frame_rate) {
      for (auto geom : elements) {
        geom->SetOrigin(geom->GetX() + 1, 0.0);
      }
      ncurses_wrapper::WindowClear();
      renderer.Draw(elements);
      ncurses_wrapper::WindowRefresh();
      timer_ptr->Reset();
    }
  }

  ncurses_wrapper::ReadInput();
  ncurses_wrapper::RestoreTerminalSettings();
}