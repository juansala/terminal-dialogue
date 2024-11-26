#ifndef GAME_HPP
#define GAME_HPP

#include <memory>
#include <vector>

#include "terminal_dialogue/game/entity_manager.hpp"
#include "terminal_dialogue/game/player.hpp"
// #include "terminal_dialogue/game/state.hpp"

class Game
{
public:
  Game();
  ~Game() {};

  void update();
  bool is_running() { return m_is_running; }
  
protected:
  bool m_is_running;
  int m_num_entities;
  EntityManager m_entity_manager;
};

#endif