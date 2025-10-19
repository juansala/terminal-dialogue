#include "terminal_dialogue/core/engine.hpp"

Engine::Engine()
: m_frame_rate{60.0} {
  ncurses_wrapper::Initialize(true, true, true, true, true);
  m_timer = std::make_shared<Timer>();
}

void Engine::Run() {
  while (m_game.IsRunning()) {
    // TODO(juansala): Use timer to set frame rate
    // TODO(juansala): Handle user input
    m_timer->Tick();
    if (m_timer->GetTime() >= 1/m_frame_rate) {
      // TODO(juansala): Move graphics into update()?
      ncurses_wrapper::WindowClear();
      Update();
      ncurses_wrapper::WindowRefresh();
      m_timer->Reset();
    }
  }
}