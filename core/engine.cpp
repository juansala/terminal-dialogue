#include "terminal_dialogue/core/engine.hpp"

void Engine::run()
{
  while (game.is_running())
  {
    update();
  }
}