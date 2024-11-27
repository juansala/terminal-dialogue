#ifndef ENGINE_HPP
#define ENGINE_HPP

// #include "terminal_dialogue/graphics/renderer.hpp"
#include "terminal_dialogue/utils/timer.hpp"
#include "terminal_dialogue/game/game.hpp"

class Engine
{
public:
  Engine(); // TODO(juansala): Add a Game::SharedPtr parameter
  ~Engine() {}

  void update() { game.update(); }
  void run();

private:
  Timer::SharedPtr m_timer;
  Game game; // Use a smart pointer?
  double m_frame_rate;
};

#endif