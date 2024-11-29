#include "terminal_dialogue/game/game.hpp"

Game::Game()
: m_is_running{ true },
  m_num_entities{ 0 }
{
  Player::SharedPtr player = std::make_shared<Player>(0, 0); // Testing player
  m_entity_manager.add_entity(player);
}

void Game::update()
{
  // TODO(juansala): Do
  m_entity_manager.update();
}
