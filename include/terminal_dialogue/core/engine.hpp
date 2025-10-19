#ifndef ENGINE_HPP
#define ENGINE_HPP

// #include "terminal_dialogue/graphics/renderer.hpp"
#include "terminal_dialogue/utils/timer.hpp"
#include "terminal_dialogue/game/game.hpp"

class Engine {
public:
  Engine(); // TODO(juansala): Add a Game::SharedPtr parameter
  ~Engine() {}

  void Update() { m_game.Update(); }
  void Run();

private:
  Timer::SharedPtr m_timer;
  Game m_game; // Use a smart pointer?
  double m_frame_rate;
};

#endif