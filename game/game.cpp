#include "terminal_dialogue/game/game.hpp"

Game::Game()
: m_is_running{ true },
  m_num_entities{ 0 }
{
  Player::SharedPtr player = std::make_shared<Player>();
  m_entity_manager.add_entity(player);
}

void Game::update()
{
  m_entity_manager.update();
}
