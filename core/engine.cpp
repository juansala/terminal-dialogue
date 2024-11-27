#include "terminal_dialogue/core/engine.hpp"

Engine::Engine()
: m_frame_rate{ 60.0 }
{
  ncurses_wrapper::initialize(true, true, true, true, true);
  m_timer = std::make_shared<Timer>();
}

void Engine::run()
{
  while (game.is_running())
  {
    // TODO(juansala): Use timer to set frame rate
    // TODO(juansala): Handle user input
    m_timer->tick();
    if (m_timer->get_time() >= 1/m_frame_rate)
    {
      // TODO(juansala): Move graphics into update()?
      ncurses_wrapper::window_clear();
      update();
      ncurses_wrapper::window_refresh();
      m_timer->reset();
    }
  }
}