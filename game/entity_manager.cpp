#include "terminal_dialogue/game/entity_manager.hpp"

void EntityManager::update()
{
  for (auto e : m_entities)
  {
    e->update();
  }

  draw();
}

void EntityManager::draw()
{
  for (auto e : m_entities)
  {
    e->draw();
  }
}

void EntityManager::add_entity(Entity::SharedPtr entity)
{
  m_entities.push_back(entity);
}